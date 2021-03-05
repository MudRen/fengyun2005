#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(WHT"舞云刀"NOR, ({ "blade" }) );
	set_weight(2000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "把");
			set("value", 10);
			set("material", "silk");
	}
	::init_blade(10);
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

