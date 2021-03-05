#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("盾牌之技", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"小册子上画着许多小人，每两个小人一组，一个拿着盾牌，另一
个拿着不同的兵器在演练。你可以试着去领悟它。（master）\n");
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "block");
		set("teaching_limit", 200);
		set("required_exp", 5000000);
        }
}
