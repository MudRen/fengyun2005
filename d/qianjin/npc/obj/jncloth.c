// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("家奴短褂", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是千金楼打手专用短褂\n");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
