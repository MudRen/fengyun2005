#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("天龙", ({ "tian long","long" }) );
    set("gender", "男性" );
    set("title", "前任淮南节度观察留后" );

    set("class","official");

    set("age", 32);
    set("long",
      "他本是朝廷命官，厌倦了官场浮华之后就退隐北疆，为人打造兵器。\n");
    set("combat_exp", 5000000);
    set("attitude", "friendly");
    set("vendor_goods", ([
	"/obj/generate/commonweapon/20/axe":20,
	"/obj/generate/commonweapon/20/blade":20,
	"/obj/generate/commonweapon/20/fist":20,
	"/obj/generate/commonweapon/20/hammer":20,
	"/obj/generate/commonweapon/20/spear":20,
	"/obj/generate/commonweapon/20/staff":20,
	"/obj/generate/commonweapon/20/sword":20,
	"/obj/generate/commonweapon/20/throwing":20,
	"/obj/generate/commonweapon/20/whip":20,
      ]) );

    set_skill("spear",200);
    set_skill("yue-spear",200);
    set_skill("force",200);
    set_skill("manjianghong",200);

    map_skill("spear","yue-spear");
    map_skill("force","manjianghong");

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: perform_action, "spear.zonghengtianxia" :),
      }) );

    setup();
    carry_object(__DIR__"obj/bigcloth")->wear();
    carry_object("/obj/weapon/spear")->wield();
}

void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}

void reset()
{
    set("vendor_goods", ([
	"/obj/generate/commonweapon/20/axe":20,
	"/obj/generate/commonweapon/20/blade":20,
	"/obj/generate/commonweapon/20/fist":20,
	"/obj/generate/commonweapon/20/hammer":20,
	"/obj/generate/commonweapon/20/spear":20,
	"/obj/generate/commonweapon/20/staff":20,
	"/obj/generate/commonweapon/20/sword":20,
	"/obj/generate/commonweapon/20/throwing":20,
	"/obj/generate/commonweapon/20/whip":20,
      ]) );
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

