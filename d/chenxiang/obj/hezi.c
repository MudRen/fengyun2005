inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("韭菜合子", ({ "hezi" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个很油腻的韭菜合子\n");
		set("unit", "个");
		set("value", 5);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
	::init_item();
}
