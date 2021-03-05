inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("明珠", ({ "pearl" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一粒圆润顺泽的明珠。\n");
		set("unit", "粒");
		set("value", 10000);
		set("food_remaining", 1);
		set("food_supply", 60);
//		set("desc_ext","补充食物(eat)");
	}
	::init_item();
}
