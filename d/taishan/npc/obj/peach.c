// chicken_leg.c

#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name("樱桃", ({ "peach" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个泰山上的樱桃,颜色俏丽。\n");
		set("unit", "堆");
		set("base_unit","个");
		set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("material", "bone");
	}
	set_amount(1);
	::init_throwing(4);
}

int finish_eat()
{
	return 0;
}
