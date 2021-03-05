#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("连击之技", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"小册子上画着许多小人，每个小人都用虚线勾勒出一套动作，
似乎是一气呵成的功夫。你可以试着去领悟它。（master）\n");
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "dual-attack");
		set("teaching_limit", 200);
		set("required_exp", 5000000);
        }
}
