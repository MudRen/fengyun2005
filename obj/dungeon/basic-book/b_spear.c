#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("基本枪法", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","小册子画着许多舞动长矛的小人，你可以试着去领悟它。（master）\n");
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "spear");
		set("teaching_limit", 120);
		set("required_exp", 5000000);
        }
}
