
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("紫衫", ({ "cloth" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 6);
	}
	::init_cloth();
}
