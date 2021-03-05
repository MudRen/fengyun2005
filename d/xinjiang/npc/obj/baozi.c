// dumpling.c

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤包子", ({ "kao baozi" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷、烤得冒油的大包子。\n");
		set("unit", "个");
		set("base_unit", "个");
                set("base_weight", 40);
                set("base_value", 30);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	set_amount(1);

}
