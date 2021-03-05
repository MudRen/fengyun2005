inherit ITEM;
inherit F_FOOD;

#include <ansi.h>
void create()
{
    set_name( YEL"龙井茶"NOR, ({ "longjing tea", "tea" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "产于苏杭一带的著名茶叶,十分普及。\n");
		set("unit", "包");
        set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
