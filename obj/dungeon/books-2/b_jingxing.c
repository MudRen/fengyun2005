#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("静行心法", ({ "book" }));
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
                
                set("teaching", "jingxing");
		set("teaching_limit", 160);
		set("required_exp", 5000000);
		set("required_class", "assassin");
		set("required_level",150);
                set("difficulty",-500);
                set("perform_name","静行五诀");    
                
        }
}