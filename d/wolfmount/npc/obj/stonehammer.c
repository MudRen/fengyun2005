// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
    set_name("大石锤", ({ "stone hammer","hammer" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一柄百八十斤的大石锤。\n");
        set("value", 1000);
        set("material", "stone");
        set("wield_msg", "$N丹田运力，拿起一把$n握在手中。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
    }
    
    ::init_hammer(20);
}
