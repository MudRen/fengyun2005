#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("奇竹朱颜", ({ "bamboo","竹子"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "一片青碧中隐透红色的异竹（pick）\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

int do_pick(string arg)
{
	object bamboo,me = this_player();
	if ( !arg && arg != "bamboo" && arg != "竹子" )
		return notify_fail("你要折什么？\n");
	message_vision(CYN"$N伸出手去掰了掰竹子。\n"NOR,me);
	if (me->query_str() < 40 /*|| environment()->query("picked")*/)	// 
		return notify_fail("这种竹子坚硬异常，竟是百折不动。\n");
	environment()->set("picked",1);
	message_vision(CYN"只听＂咔啦＂一声，一截竹竿应声而断。\n"NOR,me);
	bamboo = new(__DIR__"bamboo2");
	bamboo->move(this_player());
	destruct(this_object());
    return 1;
}

void init()
{
	add_action("do_pick","pick");
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

