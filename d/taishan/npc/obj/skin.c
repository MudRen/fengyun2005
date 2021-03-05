// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("皮水袋", ({ "waterskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的水袋，大概装得八、九升的水。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "泉水",
		"remaining": 15,
		"drunk_apply": 0,
	]) );
    ::init_item();
}
