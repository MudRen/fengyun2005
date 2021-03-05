//

inherit ITEM;
inherit F_FOOD;
inherit F_LIQUID;

void init()
{
	if(environment()==this_player())
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
}

void create()
{
	set_name("腊八粥", ({ "laba zhou", "laba" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只青花大瓷碗,里面装着热气腾腾的腊八粥。\n");
		set("unit", "碗");
		set("value", 200);
		set("food_remaining", 6);
		set("material", "food");
		set("food_supply", 90);
		set("max_liquid", 15);
		set("holiday", "腊八节");
		set("liquid", ([
                "type": "water",
                "name": "腊八粥汤",
                "remaining": 15,
                "drunk_apply": 6,
        ]) );


	}
	 ::init_item();
}

int finish_eat()
{
	if (!query("liquid/remaining"))
	{
		set_name("青花瓷碗", ({"bowl"}) );
		set("value", 10);
		set("long", "一只青花大瓷碗。\n");
		return 1;
	}
}

	