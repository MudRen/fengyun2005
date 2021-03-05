#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( "舞器", ({ "wuqi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","一把红绸舞器，细细长长，下面是环状。\n");
                set("value", 500);
                set("material", "woord");     
                set("timbre",20);
        }
        ::init_sword(10);
}


