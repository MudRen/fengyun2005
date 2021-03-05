#include <ansi.h>

inherit ITEM;
void create()
{
	set_name(YEL"黄蚯蚓"NOR, ({ "yellow worm","worm"  }) );
    	set("unit", "条");
    	set("value",5);
	set("fish_bait", 1);
    	set("long","一条用来钓鱼的普普通的黄蚯蚓。\n");
    	set_weight(1);
	::init_item();
}
