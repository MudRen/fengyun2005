// dumpling.c

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(GRN"莲蓬"NOR, ({ "lotus petal","petal" }) );
    set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个新鲜的莲蓬，绿意盎然，上面还有几滴湖水。\n");
        set("unit", "个");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
