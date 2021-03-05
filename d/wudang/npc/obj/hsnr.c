inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("红烧牛肉", ({ "fried beef", "beef" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘装满牛肉的大菜，红通通的牛肉，红通通的酱汁。\n");
		set("unit", "盘");
		set("value", 1500);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
        set_name("盘子", ({"panzi"}));
	set("value",20);
        set("long", "一只普通的大盘子，盘子边缘还掉了一块。\n");
        return 1;
}
