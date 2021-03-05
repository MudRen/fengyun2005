// color_boot.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
    set_name(  "彩靴" , ({ "color boots", "boots" }) );
    set_weight(100);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "件");
	// set("value", 800);
	set("material", "cloth");
	set("armor_prop/armor", 1);
	set("female_only", 1);
    }
    ::init_boots();
}
