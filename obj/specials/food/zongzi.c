// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"豆沙", "莲蓉", "卤肉", "百果","糯米"});
	set_name( order[random(5)] + "粽子", ({ "zongzi", "zong zi" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个还冒着热气的粽子。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "端午节");
	}
	 ::init_item();
}
int finish_eat()
{
	set_name("粽叶", ({"zong ye"}) );
	set("value", 1);
	set("long", "一个粘嗒嗒，上面还带有糯米的粽子叶。\n");
	return 1;
}	