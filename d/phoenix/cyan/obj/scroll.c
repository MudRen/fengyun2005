#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("对联", ({"对联", "scroll" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("value", 1);
		set("long", "对联上题写着：\n\n"HIM"　　　　贵大富大\n\n　　　开　　　　三\n　　　张　　　　年\n　　　吃　　　　不\n　　　三　　　　开\n　　　年　　　　张\n\n"NOR"边角处有一行小字：无言题于盆满钵满得意时。\n\n");
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
