// (C) 2000 Tie

#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("绣满了元宝的绸大褂", ({ "dagua" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
