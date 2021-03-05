#include <ansi.h>

inherit NPC;
void backattack();
int do_perform();

void create()
{

	set_name("大内高手", ({ "bodyguard" }) );
	set("long", "这是一位大内高手，专门担任保护官员之责。\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	set("class","baiyun");
	
	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);
     
	set("combat_exp", 80000);
	set_skill("sword", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("move", 50);
	set_skill("feixian-sword",5);
	set_skill("feixian-steps",5);
	
	map_skill("sword","feixian-sword");
	map_skill("dodge","feixian-steps");
	map_skill("parry","feixian-sword");
	map_skill("move","feixian-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}


int do_perform(){	
	ccommand("perform tianwaifeixian");
	return 1;
}


void leave()
{
	object owner;
	if(objectp(owner=this_object()->query("possessed")))
	{
		owner->add_temp("max_guard",-1);
		if (environment())
		{
			message("vision",name() + "说道：如再有变化，发哨为警！\n\n"
				+ name() + "闪了闪就消失不见了。\n" , environment(), this_object() ); 
        }
    }
    // Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");
    destruct(this_object());
}


//	250 + 250 = 500
void invocation(object who, int level)
{
	int i, n, hp, str, add;
	object *enemy;
	
	set("combat_exp", 20000 + who->query("combat_exp")*3/4);
	set("level", F_LEVEL->get_level(query("combat_exp")));

	if (F_ABILITY->check_ability(who,"3_huwei_lvl",3)) {
		add = query("level")+ F_ABILITY->check_ability(who,"3_huwei_lvl",3);
		set("combat_exp",F_LEVEL->level_to_exp(add,0));
	}
	
	"/feature/nada"->reset_npc(this_object());

	hp = 800 + level;
	if (who->query("family/master_id")=="master yue")
		hp = who->query("max_kee")/2; 
			
	set("max_kee",hp);
	set("max_sen",hp/2);	// 经不起精神的攻击
	set("max_gin",hp/2);
	
	str = query_str();
	delete("force_factor");
	set("str",str/2);
	
	full_me();
				
	set_skill("sword", 60 + random(level/2));
	set_skill("parry", 60 + random(level/2));
	set_skill("dodge", 60 + random(level/2));
	set_skill("move",  60 + random(level/2));
	set_skill("feixian-sword",5+who->query_skill("yue-spear",1));
	set_skill("feixian-steps",5+who->query_skill("puti-steps",1));
	
	set_leader(who);
	set("possessed",who);
	
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && (living(enemy[i])|| enemy[i]->query_temp("is_unconcious"))) {
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}
}


void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
			enemy = this_object()->query_enemy();
	        i = sizeof(enemy);
	        if (i)
	        while(i--) {
	                if( enemy[i] && living(enemy[i]) ) {
	                	if (COMBAT_D->legitimate_kill(enemy[i],owner)) {
		                        owner->kill_ob(enemy[i]);
		                        enemy[i]->kill_ob(owner);
	                	
	                	}
	                }
	        }

	}

}

void unconcious() {
	die();
}

void die()
{
	object owner;
    if(objectp(owner=this_object()->query("possessed")))
    	owner->add_temp("max_guard",-1);
	if (owner && !owner->is_ghost())	// 现在没事儿不会是ghost乐
		backattack();
	message_vision("\n$N惨叫一声，在地上打了几个滚儿，断气了。\n\n", this_object());
	destruct(this_object());
}

