// Tie@fengyun
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("短匕首", ({ "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把短而锋利的匕首\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N手中忽然出现了一把匕首。\n");
		set("unwield_msg", "$N将手中的匕首收起。\n");
	}
	init_sword(30);
}
