#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("离别剑法", ({ "book" }));
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
                
                set("teaching", "libie-sword");
		set("teaching_limit", 150);
		set("required_exp", 6400000);
                set("perform_name","离别（libie）");    
        }
}