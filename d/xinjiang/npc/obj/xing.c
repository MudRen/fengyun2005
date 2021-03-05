// copyright c apstone, inc.

inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("库车白杏", ({ "xing" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "新疆特产，杏肉发白色。\n");
		set("unit", "个");
		set("value", 55);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
	::init_item();
}
