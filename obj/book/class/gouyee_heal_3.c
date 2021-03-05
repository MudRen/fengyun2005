#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『谷衣心法·复苏灵息ＩＩＩ』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "本");
                set("material", "paper");
                set("required_class","taoist");
                set("teaching", "heal");
				set("required_exp", 6200000);
				set("required_skill", "gouyee");
                set("required_skill_level",150);
				set("grade",3);
        }
}

