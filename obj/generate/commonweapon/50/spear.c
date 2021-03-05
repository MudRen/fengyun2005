#include <weapon.h>
inherit SPEAR;

void create() {
	set_name("尽舍长枪", ({ "spear" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
//		set("long", "这是一把看起相当普通的长矛");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "steel");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_spear(50);
}
