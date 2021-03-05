
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("大铁锤", ({ "hammer" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄巨大的铁锤。\n");
		set("value", 400);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从腰间拔出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插在腰间。\n");
	}
	::init_hammer(10);
}
