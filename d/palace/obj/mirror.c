// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("护心镜", ({ "xinjing" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
