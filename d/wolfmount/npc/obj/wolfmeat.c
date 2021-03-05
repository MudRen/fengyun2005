inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name( YEL"狼肉脯"NOR, ({ "wolf meat","meat" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块腌制得又干又硬又难嚼的狼肉。\n");
		set("unit", "块");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("material", "food");
	}
	::init_item();
}
