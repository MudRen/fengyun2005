#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『幻风飘云舞·离人夜归Ｉ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 500);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","huashan");
                set("teaching", "yegui");
				set("required_exp", 1000000);
				set("required_skill", "cloud-dance");
                set("required_skill_level",150);
				set("grade",1);
        }
}

