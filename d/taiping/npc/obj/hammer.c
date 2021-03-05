#include <weapon.h>
inherit HAMMER;

void create() {
	set_name("重铁锤", ({ "hammer" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把极其沉重的大铁锤，打造的相当坚实。\n");
		set("value", 4);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_hammer(20);
}
