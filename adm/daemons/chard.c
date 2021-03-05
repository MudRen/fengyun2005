// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// chard.c
//	-- Modified by Silencer@fy4, added time restriction and no-corpse message.

#include <race.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;
        if( !stringp(race = ob->query("race")) ) {
                race = "人类";
                ob->set("race", "人类");
        }
                
        switch(race) {
                case "人类":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "妖魔":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "野兽":
                        BEAST_RACE->setup_beast(ob);
                        break;
                case "家畜":
                        STOCK_RACE->setup_animal(ob);
                        break;
                case "飞禽":
                        BIRD_RACE->setup_animal(ob);
                        break;
                case "游鱼":
                        FISH_RACE->setup_animal(ob);
                        break;
                case "蛇类":
                        SNAKE_RACE->setup_animal(ob);
                        break;
                case "昆虫":
                        INSECT_RACE->setup_animal(ob);
                        break;
                case "龙":
                        DRAGON_RACE->setup_animal(ob);
                        break;
                case "元素":
                        ELEMENT_RACE->setup_element(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

        my = ob->query_entire_dbase();

        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

        if( !ob->query_max_encumbrance() )
                ob->set_max_encumbrance( my["str"] * 20000 );

        ob->reset_action();
}

varargs object make_corpse(object victim, object killer) {
	int i;
	object corpse, *inv, *allowed, murderer, *team, ghost_item;
	
//	allowed = ({});
	if (!userp(victim) && stringp(victim->query("NO_CORPSE"))) {
		message_vision(victim->query("NO_CORPSE"),victim); //允许NPC有不留下尸体的死法
	}	
	else if(!victim->is_ghost() && !victim->is_zombie()) {
		corpse = new(CORPSE_OB);
		corpse->set_name(victim->name(1) + "的尸体", ({ "corpse" }) );
		corpse->set("long", victim->long(1) + "然而，" 
				+ gender_pronoun(victim->query("gender")) 
				+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
		corpse->set("age", victim->query("age"));
		corpse->set("gender", victim->query("gender"));
		corpse->set("race", victim->query("race"));
		corpse->set("family", victim->query("family"));
		corpse->set("victim_name", victim->name(1));
		corpse->set("victim_id", victim->query("id"));
		// Below is set to make it easier to implement revive
		if (userp(victim))	corpse->set("victim_player",1);
		// below two lines are to prevent unlimitted pet corpse burning.
		if (victim->query("possessed")) corpse->set("possessed",1);
		if (victim->query("owner")) corpse->set("possessed",1);
		// below two lines are to prevent picking up player corpse.
		corpse->set_weight(victim->query_weight()  * (userp(victim)? 100: 1)); 
		corpse->set("player",(userp(victim))?1 :0); 
		corpse->set_max_encumbrance(victim->query_max_encumbrance());
		
		//  No need to revive, no loss anyway
		if (victim->query("combat_exp")<= 12000)
			corpse->set("already_revived");
		
		// below are to setup the time restriction for picking items/corpse.see get.c
		
		corpse->set("freeze", victim->query("real_boss")? 1: 0);
		
		if (!objectp(murderer = victim->query_max_damage_dealer())) 
			murderer = victim->query_temp("last_damage_from");
				
		if (objectp(murderer)) {				
			if (objectp(murderer->query("possessed")))	
				murderer = murderer->query("possessed");
			if (arrayp(team = murderer->query_team()) && sizeof(team))
				allowed = team;
			else
				allowed = ({ murderer });
			corpse->set("allow_to_loot",allowed);
			corpse->set("killer",murderer);
		}
		corpse->set("death_time",time());
		
		corpse->set("hp",victim->query("max_kee")+victim->query("max_gin")+victim->query("max_sen"));
		corpse->set("exp",victim->query("combat_exp"));
		corpse->set("level",F_LEVEL->get_level(victim->query("combat_exp")));
		
		corpse->move(environment(victim));
	} else if (victim->is_ghost()) {
		message_vision("扑的一声，$N化成一股青烟被风吹散了。\n", victim);				
	} else {
		message_vision("$N缓缓地倒了下来，化为一滩血水。\n", victim);		
	}
	
	// Don't let wizard left illegal items in their corpses.
	if(!wizardp(victim) && victim->query("timer/insurance")+ 259200< time() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);	//物品在死后的自动转换。
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if(!inv[i]->query("no_drop")) {
				if(objectp(corpse)) {
					if((string)inv[i]->query("equipped")=="worn") {
						inv[i]->unequip();				
						inv[i]->move(corpse);
					} else if((string)inv[i]->query("equipped")=="wielded") {
						inv[i]->unequip();				
						inv[i]->move(corpse);
					} else {
						inv[i]->move(corpse);
					}	
				} else {
					if (inv[i]->query("ghostcurse_item"))
					{
						ghost_item = new("/obj/item/ghost_item");
						ghost_item->set("name",inv[i]->query("name"));
						ghost_item->set("unit",inv[i]->query("unit"));
						if (!ghost_item->move(environment(victim)))	
							destruct(ghost_item);
					} else
						inv[i]->move(environment(victim));	
				}				
			}
		}
	}
	return corpse;
}
