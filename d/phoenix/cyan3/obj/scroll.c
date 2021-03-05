#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("匾额", ({"匾额" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 1);
		set("long", "匾额上题着斗大的三字：\n\n"HIM"　　狐　　妖　　杀\n\n"NOR"匾额的后面似乎可以藏些什么．．．\n\n");
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
