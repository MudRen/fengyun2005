inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("烂瓦罐", ({ "poor pot", "pot" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个破破烂烂的烂瓦罐，里边还装了八、九升的酒。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "极品女儿红",
		"remaining": 150,
		"drunk_apply": 30,
	]) );
	::init_item();
}
