#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『血战枪法·李广射石ＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 700);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","fugui");
                set("teaching", "liguangsheshi");
				set("required_exp", 4100000);
				set("required_skill", "xuezhan-spear");
                set("required_skill_level",200);
				set("grade",2);
        }
}

