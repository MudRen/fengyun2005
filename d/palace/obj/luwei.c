#include <armor.h>
inherit MASK;


void create() {
	set_name("芦苇", ({ "luwei", "芦苇" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根中空的芦苇。\n");
		set("value", 0);
		set("wear_msg", "$N把芦苇的一头含在嘴中。\n");
		set("unequip_msg", "$N从嘴中取下芦苇。\n");
		set("armor_prop/use_under_water", 30);
		set("armor_prop/long", ({"此人嘴上含着一根长长的芦苇，像是插了根葱。\n"}) );
	}
	::init_mask();
}