#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"响尾蛇蛇胆"NOR, ({"xiangwei shedan"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long", "常见于沙漠之中响尾蛇的蛇胆，珍贵无比。\n");
                set("lore",1);
                set("unit", "个");
                set("value", 300);
        	set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
}
