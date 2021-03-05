#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(GRN"竹叶蛇蛇胆"NOR, ({"zhuye shedan"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "生于黄山翠林中的竹叶蛇蛇胆。\n");
                set("unit", "个");
                set("value", 500);
        set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
}
