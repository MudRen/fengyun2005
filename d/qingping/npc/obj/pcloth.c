// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("紫长袍", ({ "purple cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
                set("value", 30);
                set("long", "一件普普通通的紫色长袍。\n");
	}
	::init_cloth();
}
