#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("蒲团", ({ "蒲团","putuan"}) );
	set_weight(500);
	set_max_encumbrance(500);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个小小的蒲团，蒲团下似乎藏着什么物事。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


void init()
{
	if (present("蒲团",environment()) == this_object())
		if (present("蒲团 2",environment()))
			destruct(present("蒲团 2",environment()));
	add_action("do_move","move");
}

int do_move(string arg)
{
	object bamboo,me = this_player();
	if (!arg)
		return notify_fail("你要移什么？\n");
	if (!bamboo = present(arg,environment()))
		return notify_fail("你要移什么？\n");
	if (bamboo != this_object())
		return notify_fail("你要移什么？\n");
	if (bamboo=present("liaohen",environment()))
		if (!bamboo->is_fighting())
			return notify_fail("了痕师太正端坐在这个蒲团之上。\n");
	if (me->is_fighting())
			return notify_fail("你现在空不手来移蒲团！\n");

	message_vision(CYN"$N小心翼翼地移开蒲团。\n"NOR,me);
	message_vision(CYN"只见蒲团下放着什么物事，$N拾了起来，揣入怀中。\n"NOR,me);
	bamboo = new("/obj/book/chanting_51");
	bamboo->move(this_player());
	destruct(this_object());
    return 1;
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

