//	Enable officers to summon better guard.

#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("求援之术（高级）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "alert");
		set("required_exp", 6000000);
                set("required_class","official");
                set("fy41","official_alert_1");
                    
        }
}

