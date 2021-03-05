
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("红烧肉", ({ "stewed meat","meat", "肉"}) );
	set_weight(400500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一大锅香喷喷的红烧肉。\n");
		set("unit", "锅");
		set("value", 30);
		set("food_remaining", 10);
		set("food_supply", 100);
	}
	::init_item();
}

int finish_eat()
{
	set_name("大铁锅", ({ "big pot" }) );
	set_weight(50);
	set("long", "一只大铁锅。\n");
	return 1;
}
