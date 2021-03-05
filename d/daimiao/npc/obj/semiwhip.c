#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(MAG"紫炎索"NOR, ({ "whip" }) );
	set_weight(2000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "条");
			set("long", "这是一条紫色的丝索。");
			set("value", 10);
			set("material", "silk");
	}
	::init_whip(10);
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

