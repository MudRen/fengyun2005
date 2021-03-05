#include <weapon.h>
inherit WHIP;

void create() {
	set_name("铁链", ({ "chain" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("long", "这是一把公差们常用的铁链，约有三尺长。\n");
		set("wield_msg", "$N哗啦啦地拉出一条$n捏在手中。\n");
		set("unequip_msg", "$N将手中的$n放入腰间。\n");
	}
	::init_whip(10);
}
