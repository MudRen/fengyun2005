#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『九阴神抓·唯我独尊Ｉ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 800);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","shenshui");
                set("teaching", "weiwoduzun");
				set("required_exp", 5100000);
				set("required_skill", "nine-moon-claw");
                set("required_skill_level",180);
				set("grade",2);
        }
}

