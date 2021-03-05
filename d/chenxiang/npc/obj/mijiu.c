// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("米酒", ({ "mijiu", "wine" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "用米酿造的，特别适合南方人的米酒。\n");
		set("unit", "碗");
		set("value", 500);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "米酒",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
	::init_item();
}
