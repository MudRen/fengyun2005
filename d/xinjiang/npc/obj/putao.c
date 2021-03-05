// copyright c apstone, inc.

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("无核白葡萄", ({ "grape" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一串刚刚从葡萄架子上摘下来的无核白葡萄。\n");
		set("unit", "把");
		set("base_unit", "个");
                set("base_weight", 40);
                set("base_value", 30);
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
	set_amount(1);
}
