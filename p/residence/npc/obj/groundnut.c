#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(YEL"小花生"NOR, ({ "groundnut","peanut" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆坚硬的小花生。\n");
		set("unit", "堆");
		set("base_unit","个");
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("level_required",40);
		set("material", "bone");
		set("volumn",10);
	}
	set_amount(10);
	::init_throwing(50);
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
