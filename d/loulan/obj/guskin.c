
inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("古城烧", ({ "old skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "一个皮制酒袋，大概装得八、九升的关外汉子常喝的古城烧酒。\n");
		set("unit", "个");
        	set("value", 5000);
		set("max_liquid", 45);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
        	"name": "古城烧",
        	"remaining": 45,
        	"drunk_apply": 10,
	]) );
	::init_item();
}