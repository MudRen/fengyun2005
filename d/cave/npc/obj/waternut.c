// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("菱角", ({"water chestnut","chestnut" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("long", "青青翠翠的菱角。\n");
        	set("unit", "个");
        	set("value", 500);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
    ::init_item();
}
