#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『棋道·聚血ＩＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");

                set("required_class","legend");
                set("teaching", "juxue");
				set("required_exp", 6000000);
				set("required_skill", "dormancy");
                set("required_skill_level",290);
				set("grade",3);
        }
}

