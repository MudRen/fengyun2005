inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("干牛肉", ({"dry meat","meat" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块风干的牦牛腿肉。\n");
		set("unit", "块");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
