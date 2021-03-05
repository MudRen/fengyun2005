#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 5

void create()
{
	set_name("大衣橱", ({ "huge wardrobe"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("unit", "个");
	set("desc", "一个庞大的大衣橱，可惜看起来还是装不了多少东西。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","c");
	set("size",2);
	set("lore_item",1);

	set("value", 300000);
	set("tax",30);
	set("score_tax",5);
	set("max_item",MAX_ITEM);

	seteuid(getuid());
}

int is_container() {return 1;}

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
