#include <weapon.h>

inherit AXE;

void create()
{
        set_name("铁琵琶", ({ "pipa" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一个铁打的琵琶\n");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_axe(15);
}
