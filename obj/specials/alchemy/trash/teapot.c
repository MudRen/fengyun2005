// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("泥茶壶", ({ "tea pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大茶壶，大概装得几升水，里面装的东西有股怪味道。\n");
		set("unit", "个");
		set("value", 0);
		set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"name": "黑乎乎的茶水",
		"remaining": 10,
		"drunk_apply": 70,
	]) );
	::init_item();
}
