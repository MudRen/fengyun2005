// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"粗布", "棉布", "蓝布"});
        set_name((order[random(3)]) +"少林僧衣", ({ "monk clothes", "clothes"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("shaolin_cloth",1);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",100);
	}
	::init_cloth();
}
