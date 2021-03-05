#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 3

void create()
{
	set_name("雕花匣", ({ "small casket"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("prep","on");
	set("unit", "个");
	set("desc", "一个做工精细的雕花匣，匣上镶嵌着数粒明珠。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","f");
	set("size",1);
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
