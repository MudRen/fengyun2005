// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("小野", ({ "samurai ono","ono", "ono" }) );

        set("gender", "男性" );
		set("age",47);

	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"气合"NOR);
	set("title","流浪倭人");

        set("combat_exp", 4400000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );

        set_skill("kongshoudao", 140);
        set_skill("unarmed", 140);
        map_skill("unarmed", "kongshoudao");

        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("ittouryu", 190);
        set_skill("ghosty-steps", 220);

		set("max_kee",6000);

        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("dodge", "ghosty-steps");

		setup();

}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform yaozhan");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	

	if (/*!present("ono",environment()) && */!present("umezu",environment()) && !present("kiyokawa",environment()))
		environment()->c();

	::die();
	return;
}