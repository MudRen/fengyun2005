// Copyright (C) apstone, inc.

inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("馕", ({ "nang" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个硬硬的，颜色发黑的圆饼。\n");
		set("unit", "个");
		set("value", 10);
		set("food_remaining", 10);
		set("food_supply", 60);
	}
	::init_item();
	
}
