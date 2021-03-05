#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
    set_name(HIG"清团"NOR, ({ "qing tuan","tuan"}) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "清明佳节主要食物之一.\n");
		set("unit", "个");
        set("value", 100);
        set("food_remaining", 60);
		set("food_supply", 200);
		set("material", "food");
	}
	::init_item();
}
