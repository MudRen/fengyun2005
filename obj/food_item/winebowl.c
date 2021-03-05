// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大酒碗", ({ "wine bowl", "bowl" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只粗瓷大碗。");
		set("unit", "个");
		set("value", 50);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 5,
		"drunk_apply": 3,
	]) );
    ::init_item();
}

