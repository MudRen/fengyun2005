// Copyright (c) apstone, inc.
inherit ITEM;
inherit F_LIQUID;
void create()
{
    set_name("牛皮袋", ({ "cow skin", "skin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的袋，大概装得八、九升的液体。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "water",
		"name": "沙棘汁",
		"remaining": 15,
		"drunk_apply": 0,
	]) );
	::init_item();
}
