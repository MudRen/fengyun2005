// mantou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大馒头", ({ "mantou" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个白生生、热腾腾的大馒头。\n");
		set("unit", "个");
        set("value", 800);
		set("food_remaining", 9);
		set("food_supply", 60);
	}
	::init_item();
}
