inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("黑色的圆饼", ({ "black pie","pie" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个黑漆漆的饼子，据说是用粪便、月经、眼泪、脓血再混合面粉做成的。\n");
		set("unit", "个");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
