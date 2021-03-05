inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("菊花茶壶", ({ "tea pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个茶壶，大概装着菊花茶。\n");
		set("unit", "个");
		set("value", 300);
		set("max_liquid", 100);
	}

	set("liquid", ([
		"name": "菊花茶",
		"remaining": 100,
		"drunk_apply": 7,
	]) );
	::init_item();
}
