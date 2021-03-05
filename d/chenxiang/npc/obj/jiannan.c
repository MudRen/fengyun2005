// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("极品剑南春酒袋", ({ "spring wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一个牛皮缝的大酒袋，装满了沉香特产剑南春酒。\n");
		set("unit", "个");
        set("value", 20000);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
        "name": "剑南春",
		"remaining": 15,
        "drunk_apply": 30,
	]) );
	::init_item();
}
