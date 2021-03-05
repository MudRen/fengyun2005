#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("喷泉", ({ "small fountain"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个水柱冲霄的小喷泉，站在泉边片刻，衣衫就会尽湿。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","k");
	set("lore_item",1);
	set("outdoors",1);
	set("size",1);
	set("value", 100000);
	set("tax",10);
	set("score_tax",1);

	set("liq",([
				"name":"喷泉水",
				"container":"喷泉"]));

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
