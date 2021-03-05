// sword.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("镰刀", ({ "liandao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把锋利的镰刀。\n");
		set("value", 1000);
		set("material", "steel");
		set("rigidity", 30);
		set("wield_msg", "$N从腰间拔出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插在腰间。\n");
	}
	::init_blade(10);
}
