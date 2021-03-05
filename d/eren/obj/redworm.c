#include <ansi.h>

inherit ITEM;
void create()
{
	set_name( RED"红蚯蚓"NOR, ({ "red worm","worm"  }) );
    	set("unit", "条");
    	set("value",5);
	set("fish_bait_real", 1);
	set("fish_bait", 1);
    	set("long","一条用来钓鱼的红蚯蚓。\n");
    	set_weight(1);
	::init_item();
}
