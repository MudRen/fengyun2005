#include <ansi.h>
inherit "/obj/dungeon/scroll.c";

void create()
{
        set_name("血战枪法（八方风雨）", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("material", "paper");
                
                set("teaching", "faster recover");
		set("required_exp", 6400000);
                set("required_class","fugui");
                set("fy41","fg_xz_1");
                    
        }
}