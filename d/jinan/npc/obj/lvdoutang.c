// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("绿豆羹", ({ "bean geng", "geng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一碗清凉解渴的绿豆羹，消火安神，妙用无方。\n");
        set("unit", "碗");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
