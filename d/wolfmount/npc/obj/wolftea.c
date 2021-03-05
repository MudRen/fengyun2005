inherit ITEM;
inherit F_FOOD;

#include <ansi.h>
void create()
{
	set_name(GRN"狼山茶"NOR, ({ "wolf tea", "wolftea" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一种产于狼山的茶叶，绿油油的很可爱。\n");
        	set("unit", "包");
		set("value", 400);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
   	::init_item();
}
