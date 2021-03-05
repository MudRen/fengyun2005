#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 5

void create()
{
	set_name("柳编小笼", ({ "osier case"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("prep","on");
	set("unit", "个");
	set("desc", "一个柳条编织成的小笼。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","f");
	set("size",2);
	set("lore_item",1);

	set("value", 500000);
	set("tax",50);
	set("score_tax",8);
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
