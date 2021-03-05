
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("青菜", ({ "qing cai", "青菜"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗没有一点油的青菜。\n");
		set("unit", "碗");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
	::init_item();
}

int finish_eat()
{
	set_name("大菜碗", ({ "bowl" }) );
	set_weight(50);
	set("long", "一只大菜碗。\n");
	return 1;
}
