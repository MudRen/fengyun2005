#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name(HIY"南王府护卫"NOR, ({ "nanwang bodyguard","bodyguard"}) );
	set("class","berserker");
	set("attitude", "friendly");
	set("long","南王府中的高手，虽然皆为无名之辈，但身手卓绝，不逊于武林中的任一一等一的高手。\n");

	set("no_arrest",1);
	set("no_fly",1);
	set("no_curse",1);

	set("combat_exp", 6000000);	

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
		
	set_skill("spear", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("xifengying", 200);
	set_skill("unarmed",200);
	set_skill("venusfinger",200);
	set_skill("force",200);
	set_skill("gaunforce",200);
	set_skill("eclipse-spear", 200);
	map_skill("spear","eclipse-spear");
	map_skill("spear","eclipse-spear");
	map_skill("move","xifengying");
	map_skill("dodge","xifengying");
	map_skill("unarmed","venusfinger");
	map_skill("force","gaunforce");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	setup();
	carry_object(__DIR__"obj/heavyspear")->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	if (!is_busy())
		smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	ccommand("exert damageup");
	ccommand("perform panguaxe");
	if (target->query_temp("annie/eclipse_dot") || random(3))
	{
		ccommand("perform riyuetongtian");
		return;
	}
	ccommand("perform eclipse");
}

void die()
{
	object owner,*enemy;
	int i;
	if (present("nanwang prince",environment()))
		if (!userp(present("nanwang prince",environment())))
		{
			owner=present("nanwang prince",environment());
			enemy = query_enemy();
	        i = sizeof(enemy);
			owner->delete("NO_KILL");
	        while(i--)
				if( enemy[i] && living(enemy[i]) )
					if (COMBAT_D->legitimate_kill(enemy[i],owner))
					{
						owner->kill_ob(enemy[i]);
						enemy[i]->kill_ob(owner);
					}
			owner->set("NO_KILL","此人有天子威仪，不可胡乱动手，免遭官府追杀。\n");
		}
	::die();
}

void invocation(object who)
{
	object owner,*enemy;
	int i;
	message("vision", name() + "喝道：大胆！竟敢和当今天子过不去！\n" NOR,
		 environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
//	ccommand("say i="+i);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}
	set("master",who);
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
