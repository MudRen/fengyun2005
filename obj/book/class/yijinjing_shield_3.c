#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『易筋经·金光云拂ＩＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","shaolin");
                set("teaching", "shield");
				set("required_exp", 6000000);
				set("required_skill", "yijinjing");
                set("required_skill_level",200);
				set("grade",3);
        }
}

