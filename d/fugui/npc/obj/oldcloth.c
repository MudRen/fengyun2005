// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("破旧衣服", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件破旧的衣服，上面沾满油渍。\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
