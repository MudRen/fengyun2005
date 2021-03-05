#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("九阴赤炼剑法", ({ "book" }));
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
                
                set("teaching", "nine-moon-sword");
		set("teaching_limit", 250);
		set("required_exp", 5000000);
		set("required_class", "shenshui");
		set("required_level",200);
                set("difficulty",-500);
                set("perform_name","霜冷残霞（shuanglengcanxia）");    
                
        }
}