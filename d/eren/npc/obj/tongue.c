#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"沙虫肝"NOR, ({"sandworm liver","liver"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long", "沙虫的内脏，珍贵无比，传说是宫廷里的膳食之一。\n");
                set("lore",1);
                set("unit", "个");
                set("value", 3000);
        	set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
}
