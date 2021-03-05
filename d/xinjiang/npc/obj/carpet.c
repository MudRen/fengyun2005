//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name("新疆地毯", ({ "thick carpet" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块相当厚实的新疆地毯。\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_surcoat();
}
