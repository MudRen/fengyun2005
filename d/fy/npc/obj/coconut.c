#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name(YEL"椰子"NOR, ({"coconut" }) );
    set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个瘪壳皱皮的破烂椰子。\n");
		set("unit", "个");
		set("value", 0);
        set("food_remaining", 1);
		set("food_supply", 1);
	}
    ::init_item();
}

int finish_eat()
{
	object me;
	me = this_player();
	me->apply_condition("salt_drug",5+random(10));
	tell_object(me,"你一口咬下椰子，只觉得嘴里发苦发涩，原来这个椰子早已坏了。\n");
    return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

