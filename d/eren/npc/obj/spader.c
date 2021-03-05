// sword.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("采药铲", ({ "spader","short spader" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "一把短小的采药铲。\n");
        set("value", 9000);
		set("material", "steel");
	}
    init_dagger(60);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声摸出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀内。\n");


}
