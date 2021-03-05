// food.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("食物", ({"food"}));
    set_weight(40);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "毒药\n");
	set("unit", "盘");
	set("value", 0);
	set("food_remaining", 100);
	set("food_supply", 100);
    }
    ::init_item();
}

