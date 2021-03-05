// dumpling.c

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"人肉包"NOR, ({ "renroubao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个香喷喷、热腾腾的人肉大包子。\n");
		set("unit", "个");
        set("value", 30000);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
