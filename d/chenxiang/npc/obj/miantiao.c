inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("面条", ({ "miantiao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热腾腾的面条，满香的。\n");
		set("unit", "碗");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 26);
	}
	::init_item();
}
