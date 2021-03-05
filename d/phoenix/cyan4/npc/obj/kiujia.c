#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("南山藤甲", ({ "zhanjia" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "steel");
        set("value", 10);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
