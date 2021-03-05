// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("莫之许", ({ "mo zhixu","mo","zhixu" }) );
        set("title",YEL"金狮镳局"NOR);
		set("nickname",WHT"乌有子虚"NOR);
        set("gender", "男性" );

		set("age",27);

	set("chat_chance",2);
	set("chat_msg", ({
		"莫之许四处张望：老石头和土鸡？你们在哪里？\n",
		"莫之许低头按着受伤的脚，咒道：该死的，金疮药总是永远都不够用。\n",
	}) );

        set("combat_exp", 6400000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(HIR BLK"乌有刀"NOR, ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("黑色镳衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","ittouryu",2);
}
