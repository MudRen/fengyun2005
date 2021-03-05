inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;

void create()
{
	set_name(HIB"夜光杯"NOR, ({ "twilight cup", "cup" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "一个盛满了鲜红如血的葡萄美酒的夜光杯。\n");
		set("unit", "个");
		set("value", 2000);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "葡萄美酒",
		"remaining": 5,
		"drunk_apply": 20,
	]) );
}