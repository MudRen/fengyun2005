// chicken_leg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("烤猪腿", ({ "fried pig leg", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "说是猪腿,好像又长了些,瘦了些....。\n");
		set("unit", "根");
		set("value", 300);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	::init_hammer(10);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("啃得精光的腿骨", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的腿骨。\n");
	return 1;
}
