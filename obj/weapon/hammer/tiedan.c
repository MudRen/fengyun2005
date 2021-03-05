#include <weapon.h>
inherit HAMMER;

void create() {
	set_name("铁胆", ({ "tiedan","hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个沉甸甸的铁胆，打造的相当坚实。\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N拿出一个$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_hammer(35);
}
