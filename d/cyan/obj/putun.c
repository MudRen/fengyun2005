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
		set("long", "一个小小的蒲团。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

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

