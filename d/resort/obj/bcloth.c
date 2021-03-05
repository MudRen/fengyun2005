
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("黑布袍", ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
	::init_cloth();
}
