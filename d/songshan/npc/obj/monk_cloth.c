// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("褪色的少林僧衣", ({ "monk clothes", "clothes"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("shaolin_cloth",1);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
