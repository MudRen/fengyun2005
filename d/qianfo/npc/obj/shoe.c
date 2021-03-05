// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("云游僧鞋", ({ "shoes" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
				set("value",15);
        }
	::init_boots();
}
