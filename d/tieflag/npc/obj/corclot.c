// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(  "布衣" , ({ "color cloth", "cloth" }) );
    set_weight(100);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "件");
	// set("value", 4000);
	set("material", "cloth");
	set("armor_prop/armor", 10);
	set("female_only", 1);
    }
    ::init_cloth();
}
