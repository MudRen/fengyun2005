#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"佛跳墙"NOR, ({ "tasty food","food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓮美味无比的佛跳墙。\n");
		set("unit", "瓮");
		set("value", 2000);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
	::init_item();
}
