// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("烤鸡腿", ({ "fried chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝烤得干硬的鸡腿，上面粘满黑烟。\n");
		set("unit", "根");

		set("value", 0);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	::init_hammer(1);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("啃得精光的乌鸦腿骨头", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的乌鸦腿骨头。\n");
	return 1;
}
