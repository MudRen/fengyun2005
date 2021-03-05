// rice.c
inherit COMBINED_ITEM;
inherit F_FOOD;
void create()
{
	set_name("抓饭", ({ "zhua fan","rice" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一份香喷喷的抓饭，你真的想吃一口！\n");
		set("unit", "些");
		set("base_unit", "份");
                set("base_weight", 40);
                set("base_value", 100);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	set_amount(1);
}
