inherit ITEM;
inherit F_FOOD;

void create()
{
    	set_name("西瓜", ({ "watermelon" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("long", "一个滚瓜溜圆的大西瓜。\n");
		set("unit", "个");
	        set("value", 50);
	        set("food_remaining", 10);
		set("food_supply", 60);
	}
	::init_item();
}


