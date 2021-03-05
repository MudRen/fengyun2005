// 此桃花雾滴计划放在兴国谜题内--- by silencer

inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT"桃花雾滴"NOR, ({ "drop","luzhu"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", WHT"这是一滴桃花雾妖的精华凝成的露水，据说服用了后能够长生不老。\n"NOR);
		set("unit", "滴");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	object me;
	me = this_player();
	message_vision(MAG"$N的眼神里透出一阵妖异的光采！！\n"NOR, me);
	tell_object(me,MAG"你觉得自己的身子越来越轻，越来越远，似乎飘离在空中，该不是快成仙了吧！！\n"NOR);
	me->unconcious();
	destruct(this_object());
        return 1;
}
