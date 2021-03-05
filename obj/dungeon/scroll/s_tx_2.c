#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("棋道心法（聚神诀）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "jushen");
		set("required_exp", 7000000);
                set("required_class","legend");
                set("fy41","tx_jushen");
                    
        }
}