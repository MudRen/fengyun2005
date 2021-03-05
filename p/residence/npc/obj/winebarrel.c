#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("大酒桶", ({ "wine barrel"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个大酒桶，酒桶中盛的是陈年高粱酒。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","k");
	set("lore_item",1);
	set("size",1);

	set("value", 120000);
	set("tax",12);
	set("score_tax",1);

	set("liq",([
            "type":"alcohol",
            "name":"陈年高粱酒",
            "container":"大酒桶"]));

	seteuid(getuid());
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
