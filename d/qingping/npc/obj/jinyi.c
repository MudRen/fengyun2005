// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("锦衣", ({ "jin yi", "jinyi", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
                set("long", "一件丝锦做的衣服，手工十分精细。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
                set("value", 600);
	}
	::init_cloth();
}
