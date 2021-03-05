// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"槟榔"NOR, ({"betelnut" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("long", "一种地产南海附近的硬壳水果，其异味非常人所能忍受。\n");
        	set("unit", "个");
        	set("value", 500);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
    ::init_item();
}
