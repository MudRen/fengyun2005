// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("梅津", ({ "samurai umezu","umezu", "umezu" }) );

        set("gender", "男性" );
		set("age",47);

	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"独妙"NOR);
	set("title","流浪倭人");

        set("combat_exp", 4400000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("ittouryu", 190);
        set_skill("ghosty-steps", 220);

		set("max_kee",16000);

        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("dodge", "ghosty-steps");

		setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(RED"武士刀"NOR, ({ "katana" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();
}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform hyakki");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	

	if (!present("ono",environment())/* && !present("umezu",environment()) */ && !present("kiyokawa",environment()))
		environment()->c();





	::die();
	return;
}