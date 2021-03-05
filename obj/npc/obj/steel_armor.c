// steel_armor.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("重钢战甲", ({ "steel armor", "armor" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "steel");
		set("value", 9000);
                set("no_get",1);
                set("no_drop",1);

		set("armor_prop/armor", 10);
		
	}
	::init_cloth();
}
