// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("茶壶", ({ "tea pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "眉峰聚专用的大茶壶，大概装得几升水。\n");
		set("unit", "个");
		set("mark","luyu");
		set("value", 1500);
		set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"name": "茶水",
		"remaining": 10,
	]) );
	::init_item();
}
