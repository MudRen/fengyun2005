// skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("绵裙", ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "H这是件平常女子的绵裙。\n");
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	::init_cloth();
}

