inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("清炒豆芽", ({ "douya", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "雪白的豆芽根根饱满，上面撒了些翠绿的葱丝。\n");
		set("unit", "盘");
		set("value", 2);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
        set_name("盘子", ({"panzi"}));
		set("value",2);
        set("long", "一只白底儿蓝花的大盘子。\n");
        return 1;
}
