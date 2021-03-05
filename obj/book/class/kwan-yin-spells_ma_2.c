#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『观音六字明咒·嘛』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 800);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","lama");
                set("teaching", "ma");
				set("required_exp", 2700000);
				set("required_skill", "kwan-yin-spells");
                set("required_skill_level",150);
				set("grade",2);
        }
}

