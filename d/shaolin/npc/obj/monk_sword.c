#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("檀木剑", ({ "sword", }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "bamboo");
        set("long", "这是一把用上好的檀木做成的剑，手工细腻别致。\n");
        set("wield_msg", "$N拿出一把别致的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
    init_sword(27);
}
