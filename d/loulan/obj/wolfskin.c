inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name( RED"狼酒袋"NOR, ({ "wolf skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一坛醇香芳冽，艳红似血的美酒。\n");
		set("unit", "个");
		set("value", 200000);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "狼酒",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
   	::init_item();
}
