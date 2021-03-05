// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("西夏帕耳", ({ "hammer" }) );
        set_weight(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "据传本来是蒙古铁骑常用的六棱铁锤，后来传入藏边关外。\n");
                set("value", 600000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_hammer(20);
}
