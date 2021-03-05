// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("迷糊的小二", ({ "waiter" }) );
	set("title",YEL"四海客栈"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正躺在一张桌上，迷迷糊糊地打着瞌睡。\n");
	set("price_modifier",10000);
	set("combat_exp", 3700000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		__DIR__"obj/food1" : 50,
		__DIR__"obj/food2" : 50,
		__DIR__"obj/food3" : 50,
		__DIR__"obj/tea1" : 50,
		__DIR__"obj/tea2" : 50,
	]) );
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(25) :),
        }) );

	setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("金线绸衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",200,150,0,"/obj/weapon/","fighter_w","herb",1);

}


void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

void reset(){
		set("vendor_goods", ([
		__DIR__"obj/food1" : 50,
		__DIR__"obj/food2" : 50,
		__DIR__"obj/food3" : 50,
		__DIR__"obj/tea1" : 50,
		__DIR__"obj/tea2" : 50,
	]) );
}