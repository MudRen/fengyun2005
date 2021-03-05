// shield.c

#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("牛皮盾", ({ "leather shield", "shield" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
		set("value", 340);
		set("armor_prop/armor", 5);
	}
	::init_shield();
}
