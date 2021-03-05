#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("佛跳墙", ({ "inesculent food","food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓮……恩，看起来已经坏掉的佛跳墙。\n");
		set("unit", "瓮");
		set("value", 500);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
	::init_item();
}
