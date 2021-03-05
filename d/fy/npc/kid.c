#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("小僮仆", ({ "opera waiter" }) );
	set("gender", "男性" );
	set("cor",10);
	set("age", 12);
    set("title", CYN"梨园中人"NOR);
	set("long",
		"一个还没长成的小僮仆，正在戏院里当班。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("rank_info/respect", "小老弟");
	set("vendor_goods", ([
		__DIR__"obj/peanut" : 50,
		__DIR__"obj/tea" : 50,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	::init();
	add_action("do_vendor_list", "list");
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
