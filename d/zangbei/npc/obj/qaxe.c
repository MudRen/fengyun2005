#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name( "手斧", ({ "handaxe" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","斧柄短小，却异常锋利。\n");
                set("value", 500);
                set("material", "skin");

        }
        ::init_axe(20);
}


