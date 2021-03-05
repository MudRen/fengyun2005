#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"熊掌"NOR, ({"bear palm","palm"}) );
    set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long", "冬眠野熊的手掌，又胖又嫩。\n");
                set("winter",1);
                set("unit", "只");
                set("value", 300);
        		set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
}
