#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『寒凛罗血·册四』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

				set("value", 1000);
                set("unit", "本");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "hanlingluoxue");
				set("required_exp", 6400000);
				set("required_skill", "snowforce");
                set("required_skill_level",175);
				set("grade",4);
        }
}

