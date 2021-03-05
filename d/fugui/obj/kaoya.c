// kaoya.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤鸭", ({ "kaoya" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只香喷喷的烤鸭。\n");
		set("unit", "只");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
	::init_item();
}
