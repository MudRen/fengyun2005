inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("热气腾腾的青菜", ({ "hot greens" ,"greens"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的大米饭。\n");
		set("unit", "碗");
		set("value", 45);
		set("food_remaining", 10);
		set("food_supply", 40);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
        set_name("粗碗", ({"bowl"}));
	set("value",10);
        set("long", "一只粗瓷大碗。\n");
        return 1;
}
void init()
{
	::init();
	call_out("cold",100+random(100));
	
}

void cold()
{
	set_name("冷掉的青菜", ({ "cold greens" ,"greens"}) );
	set("long", "一碗已经冷了的青菜。\n");
}
