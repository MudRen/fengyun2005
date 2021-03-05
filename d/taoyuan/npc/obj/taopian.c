// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("桃片糕", ({ "taopian cake", "cake" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个雪白的，上面有桃红色斑点的桃片糕。\n");
		set("unit", "个");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
    ::init_item();
}
