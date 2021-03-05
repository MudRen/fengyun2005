inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("竹叶青酒袋", ({ "zhuskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
	::init_item();
}
