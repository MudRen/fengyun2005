// chicken_leg.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
    set_name(HIR"鲜血淋漓的人腿"NOR, ({ "blood leg", "leg" }) );
    set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一截烧烤的热气腾腾的大腿，但仔细一看，竟然似乎是人。。\n");
		set("unit", "根");
        set("value", 10000);
		set("food_remaining", 4);
		set("food_supply", 40);
        set("wield_msg", "$N举起一根$n，挥舞起来。\n");
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
