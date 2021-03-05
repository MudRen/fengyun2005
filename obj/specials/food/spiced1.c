// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(YEL"卤牛肉"NOR, ({"spiced beef", "beef" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块喷香喷香的卤牛肉。\n");
		set("unit", "块");
		set("value", 500);
		set("finish_msg",CYN"$N张嘴咬了一口"+this_object()->query("name")+"，咂咂嘴舔舔唇回味了数秒，将"+this_object()->query("name")+"飞快地啃个精光。\n"NOR);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object ob;
	mapping buff;
	ob = this_player();
	if (!ANNIE_D->check_buff(ob,"strup"))
	{
			buff =
			([
				"caster":ob,
				"who":ob,
				"type":"strup",
				"att":"bless",
				"name":"小吃摊·卤牛肉",
				"buff1":"apply/strength",
				"buff1_c":1,
				"time":60+random(120),
				"buff_msg":HIR"$N"HIR"突然觉得浑身充满了力量！\n"NOR,
			]);
			ANNIE_D->buffup(buff);
	}
	return;
}


// 凝輕·dancing_faery@hotmail.com

