#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create() {
	set_name("相思刀", ({"xiangsi blade", "blade" }));
    	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "把");
		set("long", "刀相思，人相依，常相偎。\n");
		set("value", 0);
		set("block_rate",5);
		set("block_level",0);
	}
	::init_shield();
}


