inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    	object weapon;
		set_name("老老常", ({ "boss old tsang","boss","old tsang","tsang","boss tsang"}) );
		set("gender", "男性" );
		set("title",HIR"登高一呼 应者云集"NOR);
		set("class","shaolin");
		set("age",81);
		set("long","老老常是常老大的父亲，年事已高，洗手不干，享受着老太爷的福气。
不过他的号召力即使是常老大也望尘莫及……\n");

		set("spawn_location","/d/oldpine/keep5");
        set("gender", "男性" );
    
		set("gold_reward", 7);
		
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 850000);	// Cap @ L25.
    
        set_skill("dodge", 200);
        set_skill("puti-steps",120);	
		set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("shortsong-blade",102);	
		
        map_skill("dodge", "puti-steps");
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
		
		set("max_kee",6000);
		set("max_gin",3000);
		set("max_sen",3000);
        

//老老常 老凇寨 (无物无我) (召唤土匪) (召唤山贼) 

		setup();

		weapon=carry_object("/obj/weapon/blade");
		weapon->set_name(RED"砍人头"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(RED"沾满油污的衣服"NOR, ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();

	set("drop/fixed_amount",1);
	set("drop/fixed_drop", ({
		BOOKS"learn/magic_60",
		BOOKS"learn/spells_100",
		BOOKS"learn/iron-cloth_75.c",
	}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",2);
	set("drop/common_drop",({
"/obj/generate/wrists_25_1.c",
"/obj/generate/surcoat_25_2.c",
"/obj/generate/neck_25_12.c",
"/obj/generate/head_25_12.c",
"/obj/generate/boots_25_13.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

	::die();
	return;
}

int kill_ob(object who)
{
        ::kill_ob(who);
//        smart_fight();
        return 1;
}

void dist(object ghost)
{
	if (!ghost)
		return;
	message_vision(BLU"$N叫道：点子爪子硬，扯乎扯乎！\n"NOR,ghost);
	destruct(ghost);
	return;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object *enemy;
	int i;

	set("atman",query("max_atman")*2);

	if (time()>query("annie/sh")+40 && time()>query("annie/ec")+10 )
	{
		message_vision(BMAG YEL"\n召唤土匪\n"NOR,this_object());
		message_vision(CYN"\n老老常将竹哨放在嘴边，吹出一声凄厉无比的锐啸，一个土匪屁颠屁颠地跑了出来。\n\n"NOR,this_object());
		ob = new("/d/oldpine/npc/bandit_chief");
		ob->set("title","老云寨");
		ob->set("name","土匪");
	    ob->set("attitude","friendly");

		ob->move(environment());
		set("annie/sh",time());

		enemy=query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				ob->kill_ob(enemy[i]);
				enemy[i]->kill_ob(ob);
			}
		}
		ob->set("possessed",this_object());
		call_out("dist",120,ob);
	}

	if (time()>query("annie/sh")+10 && time()>query("annie/ec")+40 )
	{
		message_vision(BMAG YEL"\n召唤山贼\n"NOR,this_object());
		message_vision(CYN"\n老老常将竹哨放在嘴边，吹出一声凄厉无比的锐啸，一个山贼屁颠屁颠地跑了出来。\n\n"NOR,this_object());
		ob = new("/d/oldpine/npc/tall_bandit");
		ob->set("name","山贼");
	    ob->set("attitude","friendly");
		ob->move(environment());
		set("annie/ec",time());

		enemy=query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				ob->kill_ob(enemy[i]);
				enemy[i]->kill_ob(ob);
			}
		}
		ob->set("possessed",this_object());
		call_out("dist",120,ob);
	}
	
	ccommand("perform dodge.wuwuwuwo");
	return;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

