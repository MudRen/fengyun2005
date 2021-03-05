// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIR BLK"牛肉面"NOR, ({"beef noodles", "noodles" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗大碗牛肉面。\n");
		set("unit", "碗");
		set("value", 100);
		set("finish_msg",CYN"$N唏哩呼噜地将"+this_object()->query("name")+"吃了个精光，把碗向桌上一拍，叫道：老板，再来一碗！\n"NOR);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object me;
	me = this_player();
	me->set("food",me->max_food_capacity()*2);
	return;
}
// 凝輕·dancing_faery@hotmail.com

