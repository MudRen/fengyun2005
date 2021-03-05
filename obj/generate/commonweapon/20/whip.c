
#include <weapon.h>
inherit WHIP;

void create() {
	set_name( "断打铁鞭", ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 2000);
		set("weapon_prop/attack",10);
		set("level_required",10);
		set("material", "skin");        
		set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n束在腰间。\n");
	}
	::init_whip(20);
}

