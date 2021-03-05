inherit F_FOOD;
inherit ITEM;

void create()
{
    	set_name("白煮鸡蛋", ({ "egg"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "一个剥了壳的白煮鸡蛋。\n");
        	set("unit", "个");
        	set("value", 200);
        	set("food_remaining", 4);
		set("food_supply", 40);
		set("material", "food");
	}
	::init_item();
}
