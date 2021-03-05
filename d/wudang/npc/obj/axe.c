
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("砍柴斧", ({ "axe" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄锋利的砍柴斧。\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从腰间拔出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插在腰间。\n");
	}
	::init_axe(10);
}
