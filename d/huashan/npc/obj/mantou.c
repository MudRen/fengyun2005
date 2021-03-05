//

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("夹着五花肉的馒头", ({ "meat mantou", "mantou" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个夹着五花肉的大馒头，油油的，吃起来一定很香。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 10);
		set("material", "food");
		set("food_supply", 40);

	}
	 ::init_item();
}


	