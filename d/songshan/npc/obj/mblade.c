
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("长柄窄刃刀", ({ "long blade" }) );
    set_weight(7000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把东瀛武士常用的刀");
        set("value", 300);
    set("rigidity", 2000);
        set("material", "steel");
    }
    ::init_blade(10);
}

