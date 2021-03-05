inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("风鸡", ({ "chicken" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只美味可口的风鸡。\n");
		set("unit", "个");
		set("value", 4);
		set("food_remaining", 30);
		set("food_supply", 60);
	}
	::init_item();
}
