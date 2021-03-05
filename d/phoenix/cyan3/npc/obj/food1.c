#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(CYN"包子"NOR, ({ "dumpling"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个又冷又硬的素馅包子。\n");
		set("unit", "个");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	::init_item();
}
