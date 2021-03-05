// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("阳炎", ({ "yang yan","yang","yan" }) );
        set("title",YEL"金狮镳局"NOR);
		set("nickname",CYN"大刀"NOR);
        set("gender", "男性" );

		set("age",47);

        set("combat_exp", 3400000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(25) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("护手刀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("蓝色镳衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name(HIY"金耀狮子旗"NOR, ({ "flag" }) );
		weapon->set("long","一面绣纹着黄金狮子的大旗。");
		weapon->set("value",0);

    	auto_npc_setup("ouyang",200,150,0,"/obj/weapon/","fighter_w","shortsong-blade",1);
}
