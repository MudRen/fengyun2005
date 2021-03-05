#include <weapon.h>

inherit SPEAR;
inherit F_VO;

void create()
{
        set_name("长枪", ({ "spear" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根长枪。\n");
                set("value", 100);
                set("material", "steel");
        }
        init_spear(10);
}
