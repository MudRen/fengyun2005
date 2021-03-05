#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(YEL"肥肠"NOR, ({ "intestine" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一条又粗又大的肥肠。\n");
		set("unit", "条");
       		set("food_remaining", 5);
		set("food_supply", 90);
       		set("material", "rib");
	}
        ::init_item();
}
