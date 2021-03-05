
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("粗米饭", ({ "rice", "白饭"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗粗米饭。\n");
		set("unit", "碗");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
	::init_item();
}

int finish_eat()
{
	set_name("粗瓷碗", ({ "bowl" }) );
	set_weight(50);
	set("long", "一只粗瓷碗。\n");
	return 1;
}
