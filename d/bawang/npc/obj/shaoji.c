#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("烧鸡", ({ "meat" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一只香喷喷的烤烧鸡!\n");
		set("unit", "只");
        set("value", 800);
        set("food_remaining", 6);
		set("food_supply", 50);
        set("material", "rib");
	}
        ::init_hammer(2);
}

int finish_eat()
{
        set_name("烧鸡骨头", ({ "rib" }) );
        set_weight(250);
        set("long", "啃得精光的少鸡骨头。\n");
        return 1;
}

	
