inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糌粑", ({ "zanba" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的用手捏成的大饭团，是藏人爱吃的食物，也是上好的鱼饵。\n");
		set("unit", "个");
		set("value", 15);
		set("fish_bait_zanba", 1);
		set("fish_bait", 1);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
