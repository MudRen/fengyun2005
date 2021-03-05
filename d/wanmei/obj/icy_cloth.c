// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(  "吹雪残云衣" , ({ "icy cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 0);
	    	set("male_only", 1);
	}
	::init_cloth();
}
