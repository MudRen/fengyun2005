// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("古城烧", ({ "old skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个皮制酒袋，大概装得八、九升的关外汉子常喝的古城烧酒。\n");
		set("unit", "个");
        set("value", 1500);
		set("max_liquid", 450);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
        "name": "古城烧",
        "remaining": 450,
        "drunk_apply": 100,
	]) );
	::init_item();
}
