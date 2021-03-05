// rice.c
inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("哈密瓜", ({ "hami gua" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个又香又脆的哈密瓜，闻起来都是那么香！\n");
		set("unit", "些");
		set("base_unit", "个");
                set("base_weight", 40);
                set("base_value", 10);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	set_amount(1);
}
