// bamboo_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;


void create()
{
        set_name(GRN"翠竹枪"NOR, ({ "bamboo spear", "spear" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一把翠竹削成的竹枪，枪尖处用布包了起来以免误伤同伴。\n");
                set("wield_msg", "$N抽出一把练枪用的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        ::init_spear(10);
}
 
