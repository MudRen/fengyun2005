// by tie@fengyun

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(GRN"黄瓜"NOR, ({ "cucumber" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一条墨绿水灵的黄瓜.\n");
        set("unit", "条");
        set("value", 50);
        set("food_remaining", 5);
		set("food_supply", 60);
	}
	::init_item();
}
