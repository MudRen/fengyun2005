#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("梨花枪", ({ "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根喋血沙场上的将士常用的长枪。\n");
                set("value", 1);
                set("material", "steel");
        }
        init_spear(2);
}
