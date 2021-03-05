#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("天地人魔连环八式", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",(: description() :));
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "demon-blade");
		set("teaching_limit", 150);
		set("required_exp", 6400000);
                set("perform_name","［天地人魔］（tiandirenmo）");    
        }
}