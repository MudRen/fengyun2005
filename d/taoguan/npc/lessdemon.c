// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>

inherit NPC;
void create()
{

	set_name("凶骸", ({ "lesser demon","demon" }) );
	set("long", "这是一具战死沙场仍不自知，而被人用邪术所控的凶骸。\n");
	set("race", "野兽");
	set("attitude", "friendly");
	set("title",YEL"大光明教"NOR);
	set("nickname",WHT"亡者不息"NOR);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 4000000);

	set("bellicosity", 30000 );
    set("attitude", "aggressive");

	set("max_kee",20000);
	set("max_gin",10000);
	set("max_sen",10000);

	set("limbs", ({ "头部", "身体", }) );
	set("verbs", ({ "bite", "claw" }) );

	set("str",60);

	set_skill("blade", 200);
	set_skill("spring-blade",200);
	set_skill("unarmed",200);
	set_skill("yue-strike",200);
	
	map_skill("unarmed","yue-strike");
	map_skill("blade","spring-blade");

	setup();
	carry_object(__DIR__"obj/demonblade")->wield();
}

void call_die()
{
	if( environment() ) {
			say( "\n"+name() + "倒在地上，一瞬间就没进地里消失了。\n\n");
	}
	destruct(this_object());
}

void die()
{
	call_die();
}

/*
void die()
{
	object owner,enemy;
	set_name("凶骸", ({ "x x x x x" }) );
	if ( present("lesser demon",environment() ) )
		call_die();
	else
	{
	    if(objectp(enemy=query_temp("last_damage_from")))
		    if(owner=enemy->query("possessed"))
				enemy = owner;
		if (enemy)
		{
			message_vision(CYN"\n你听到一阵笑声，有人在慢慢的鼓掌。\n"NOR,enemy);
			message_vision(CYN"一个声音道：不错，不错，果然精彩。\n"NOR,enemy);
			message_vision(CYN"你眼前的黑雾忽然散开，原来你还在小室之中，而辛望就站在你面前四尺之外。\n\n"NOR,enemy);
			enemy->set_temp("annie/demon_xin_1",0);
			enemy->set_temp("annie/demon_xin_2",1);
			enemy->move(load_object("/d/taoguan/dimroom"));
		}
		call_die();
		return ;
	}
}


*/
