// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "绣花鞋", ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("value", 30);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	::init_boots();
}
