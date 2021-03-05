#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("冰心诀（寒心诀）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "iceheart_mark");
		set("required_exp", 6400000);
                set("required_class","yinshi");
                set("fy41","dwg_ih_buffup");
                    
        }
}