//

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("椒盐花生", ({ "peanut" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小碟炸的酥脆的椒盐花生。\n");
		set("unit", "碟");
		set("value", 100);
		set("food_remaining", 6);
		set("material", "food");
		set("food_supply", 20);

	}
	 ::init_item();
}

int finish_eat()
{
	set_name("小碟子", ({"plate"}) );
	set("value", 10);
	set("long", "一只小小的粗磁碟子。\n");
	return 1;
}

	