// jiutan.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒坛子", ({ "jiutan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个青瓷酒摊，花纹精细，里面想来装的也是美酒。\n");
		set("unit", "个");
		set("value", 5000);
		set("max_liquid", 2000);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "zhuyeqing",
		"name": "竹叶青",
		"remaining": 2000,
		"drunk_apply": 6,
	]) );
	::init_item();
}
