#include <weapon.h>
inherit HAMMER;

void create() {
	set_name("洗衣锤", ({ "laundry hammer","hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把用红山木打造的用来洗衣服的锤子。\n");
		set("value", 3);
		set("material", "wood");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_hammer(10);
}
