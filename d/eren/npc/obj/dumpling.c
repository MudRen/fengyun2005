inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("水晶包子", ({ "dumpling" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个小小的糯米包子，黑芝麻的馅子。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 3);
		set("food_supply", 300);
	}
	::init_item();
}
