
#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("白毛巾", ({ "white towel", "towel" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条干干净净的大白毛巾\n");
		set("unit", "条");
		set("value", 20);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}

