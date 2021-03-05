#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 6

void create()
{
	set_name("青石桌", ({ "stone table"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("prep","on");
	set("unit", "个");
	set("desc", "一张青青石板桌。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","e");
	set("outdoors",1);
	set("size",2);
	set("lore_item",1);

	set("value", 150000);
	set("tax",15);
	set("score_tax",2);
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
