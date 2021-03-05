#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(WHT"雪团"NOR, ({ "snowball"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一团没有化开的雪块。\n");
		set("unit", "堆");
		set("volumn",10);
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(10);
	init_throwing(70);
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
