#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("黑木箱", ({ "woodcase"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个乌黑的大木箱子，被摆放在这间屋子的一角。\n");
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

