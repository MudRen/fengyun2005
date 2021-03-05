#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("粗布麻衣", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("material", "cloth");
		set("unit", "件");
		set("value", 100);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
