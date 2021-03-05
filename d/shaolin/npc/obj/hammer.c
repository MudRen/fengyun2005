#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("流星锤", ({ "flying hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把用铁链子栓着的铁锤\n");
                set("value", 40);
                set("level_required", 55);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(65);
}
