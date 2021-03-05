#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『天河一线·增进精研』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

				set("value", 1000);
                set("unit", "本");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "tianheyixian");
				set("required_exp", 6400000);
				set("required_skill", "starrain");
                set("required_skill_level",200);
				set("grade",2);
        }
}

