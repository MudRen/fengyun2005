// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("竹剑", ({ "bamboo sword", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一把练习剑法用的竹剑，剑尖处用布包了起来以免误伤同伴。\n");
                set("wield_msg", "$N拿出一把练剑用的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        ::init_sword(10);
}
 
