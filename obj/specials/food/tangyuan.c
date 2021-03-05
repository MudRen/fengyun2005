// tangyuan

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"豆沙", "莲蓉", "枣泥", "凤梨", "百果", "肉馅"});
	set_name(order[random(6)] + "汤圆", ({ "tang yuan", "tangyuan" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的元宵。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "元宵节");
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("青花瓷碗", ({"bowl"}) );
	set("value", 10);
	set("long", "一只青花大瓷碗。\n");
	return 1;
}

	