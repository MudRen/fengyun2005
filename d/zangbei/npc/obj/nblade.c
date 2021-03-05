#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name( "铲子", ({ "spade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long","一把手柄很短的铲子。\n");
                set("value", 500);
                set("material", "wood");
        }
        ::init_blade(10);
}


