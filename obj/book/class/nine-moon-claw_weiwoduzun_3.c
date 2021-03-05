#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『九阴神抓·唯我独尊ＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","shenshui");
                set("teaching", "weiwoduzun");
				set("required_exp", 6400000);
				set("required_skill", "nine-moon-claw");
                set("required_skill_level",200);
				set("grade",3);
        }
}

