#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『雪野潜踪·虎踞ＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 500);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","wolfmount");
                set("teaching", "feline");
				set("required_exp", 3000000);
				set("required_skill", "xueyeqianzong");
                set("required_skill_level",160);
				set("grade",2);
        }
}

