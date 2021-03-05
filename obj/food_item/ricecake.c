inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("饭团", ({ "rice" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的大饭团，里面夹着生虾片。\n");
		set("unit", "个");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
