inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸡蛋", ({ "chicken egg","egg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个煮熟了的红壳鸡蛋。\n");
		set("unit", "个");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}


void init() {
	::init();
	if (!query("decaying")) {
		call_out("badegg", 180);
		set("decaying",1);
	}
	return;
}

void badegg() {
	set("long", "已经不再新鲜的蛋里散发出臭味。\n");
	set("name", "臭蛋");
	set("value", 0);
	return;
}
