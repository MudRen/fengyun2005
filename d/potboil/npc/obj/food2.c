#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"水"HIR"炎"CYN"双生果"NOR, ({ "carrot"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 2000);
		set("food_remaining", 60);
		set("food_supply", 250);
	}
	::init_item();
}
