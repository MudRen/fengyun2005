#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(WHT"乱棍打死猪八戒"NOR, ({ "entry"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "盆里铺底的是一大块山猪肉，上面高高地堆着许多豆芽。\n");
		set("unit", "盘");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
        set_name("盘子", ({"panzi"}));
		set("value",200);
        set("long", "一只蓝底儿雕花的景泰蓝大盘子。\n");
        return 1;
}
