// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(WHT"猪脚面"NOR, ({"pork noodles", "noodles" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗大碗猪脚面。\n");
		set("unit", "碗");
		set("value", 100);
		set("finish_msg",CYN"$N唏哩呼噜地将"+this_object()->query("name")+"吃了个精光，又意尤未竟地将碗捧起，把剩下的汤汁灌了个底朝天。\n"NOR);
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
	me->set("water",me->max_water_capacity()*2);
	return;
}
// 凝輕·dancing_faery@hotmail.com

