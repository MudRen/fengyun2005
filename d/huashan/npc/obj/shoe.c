// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("登山鞋", ({ "shoes" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
        }
	::init_boots();
}
