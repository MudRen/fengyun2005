#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("短矛", ({ "spear" }) );
	set_weight(2000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一把看起相当普通的矛，不过只有一尺长短。\n");
		set("value", 800);
		set("material", "steel");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_spear(20);
}
