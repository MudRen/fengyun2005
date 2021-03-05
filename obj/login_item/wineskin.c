// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("羊皮酒袋", ({ "wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个羊皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
	//	set("value", 20);
		set("max_liquid", 4500);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 4500,
		"drunk_apply": 7,
	]) );
	::init_item();
}
