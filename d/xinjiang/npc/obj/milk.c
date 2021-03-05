// Copyright (c) apstone, inc.
inherit ITEM;
inherit F_LIQUID;
void create()
{
	set_name("装马奶子的皮袋", ({ "horse skin", "skin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个马皮缝的袋，大概装得八、九升的马奶子。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "water",
		"name": "马奶子",
		"remaining": 15,
		"drunk_apply": 0,
	]) );
	::init_item();
}
