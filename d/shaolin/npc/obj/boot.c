// boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("鹿皮小靴", ({ "deer boots","boots" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "双");
                set("value", 100);
        }
	::init_boots();
}
