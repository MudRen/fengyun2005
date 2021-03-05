inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("喜糖", ({ "candy"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一包糖果，袋子上面绣着“龙凤呈祥”四个字。\n");
		set("unit", "包");
		set("value", 400);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
