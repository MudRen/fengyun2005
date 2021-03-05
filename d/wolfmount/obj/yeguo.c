// copyright c apstone, inc.

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(RED"野果"NOR, ({"ye guo","guo" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("long", "一个暗红色的野果，叫不出什么名字，有点象狼桃，散发着诱人的香味。\n");
        	set("unit", "个");
        	set("value", 500);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
    ::init_item();
}
