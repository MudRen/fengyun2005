// waterskin.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒瓶", ({ "wine bottle", "bottle" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个式样古朴的酒瓶。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 450);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "清酒",
		"remaining": 450,
		"drunk_apply": 5,
	]) );
}

void init()
{
	function f;
	object ob;
	
	::init();	
	f = (: call_other, __FILE__, "drink_drug" :);
	set("liquid/drink_func", bind(f, this_object()));
	set("saki",1);
}

int drink_drug(object ob)
{
	if(!userp(this_player())) return 0;
	message_vision(HIR"$N只觉腹中一阵绞痛，一头倒了下去。\n"NOR,this_player());
	this_player()->set_temp("last_damage_from","误饮毒酒身亡。\n");
	this_player()->die();

	return 0;
}