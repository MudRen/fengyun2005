inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大碗茶", ({ "tea bowl","bowl" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个粗瓷大碗。\n");
		set("unit", "个");
		set("value", 1000);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "tea",
		"name": "大碗茶",
		"remaining": 9,
		"drunk_apply": 0,
	]) );
	::init_item();
}
