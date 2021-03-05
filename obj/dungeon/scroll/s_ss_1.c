#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("绝处逢生", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "weiwoduzen");
		set("required_exp", 6000000);
                set("required_class","shenshui");
                set("fy41","shenshui_weiwoduzun");
                    
        }
}