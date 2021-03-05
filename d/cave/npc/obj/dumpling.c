// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大包子", ({ "dumpling" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个黑乎乎的大包子,里面的肉有些酸。\n");
		set("unit", "个");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
