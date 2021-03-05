// copyright c apstone, inc.

inherit COMBINED_ITEM;
inherit F_FOOD;
void create()
{
	set_name("葡萄干", ({ "putaogan" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把闻起来都甜得呛人的葡萄干。\n");
		set("unit", "把");
		set("base_unit", "粒");
                set("base_weight", 40);
                set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
	set_amount(1);
}
