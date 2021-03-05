#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("遁天符（边城）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "Drift to biancheng");
		set("required_exp", 4000000);
                set("required_class","taoist");
                set("fy41","taoist_drift_1");
                    
        }
}