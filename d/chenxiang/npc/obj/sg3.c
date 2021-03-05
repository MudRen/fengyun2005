inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("云母粉", ({ "yunmufen" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一种相当罕见的菜肴，别说吃，你连见都没见过。\n");
		set("unit", "盘");
        set("value", 1200);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
	::init_item();
}
