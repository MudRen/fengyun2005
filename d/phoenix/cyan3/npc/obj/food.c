inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("乾粮", ({ "food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块硬梆梆的乾粮。\n");
		set("unit", "块");
		set("value", 5);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
