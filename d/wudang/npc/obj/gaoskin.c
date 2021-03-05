inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("高粱酒袋", ({ "gaoskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "高粱酒",
		"remaining": 25,
		"drunk_apply": 30,
	]) );
}