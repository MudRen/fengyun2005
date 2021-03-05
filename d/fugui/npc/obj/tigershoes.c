#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "虎头鞋", ({ "tiger shoes", "shoes"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("value", 300);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	::init_boots();
}
