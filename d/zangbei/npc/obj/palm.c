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
            	set("long", "野熊的手掌，不过这头熊看来刚过了冬天，瘦得很。\n");
                set("unit", "只");
                set("value", 300);
        		set("food_remaining", 10);
                set("food_supply", 60);
        }
    ::init_item();
}
