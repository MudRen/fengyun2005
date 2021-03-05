// lumber_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("铁斧", ({ "lumber axe", "axe" }) );
	set_weight(22000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把沈重的铁斧，用来砍柴。\n");
		set("value", 11);
		set("wield_msg", "$N拿出一把砍柴用的$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_axe(11, TWO_HANDED);
}
