// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(HIG"香梨"NOR, ({ "pear" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "一个看上去让人流口水的大香梨。\n");
        	set("unit", "个");
        	set("value", 500);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
