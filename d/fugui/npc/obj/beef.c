inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("酱牛肉", ({ "beef"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块刚刚出锅的酱牛肉，还直冒热气\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 100);
		set("material", "food");
	}
	::init_item();
}
