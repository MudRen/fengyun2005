inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("牛皮酒袋", ({ "wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 2000);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "山西清酒",
		"remaining": 15,
		"drunk_apply": 10,
	]) );
	::init_item();
}
