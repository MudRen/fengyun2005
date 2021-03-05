// hammer.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIW"霹雳锤"NOR, ({ "hammer" }) );
        set_weight(400000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "根据化外三仙之一怒道人的兵器炼制。\n");
                set("value", 600000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_hammer(20);
}
