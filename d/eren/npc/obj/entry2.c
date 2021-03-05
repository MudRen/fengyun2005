#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(HIR"火辣辣的吻"NOR, ({ "entry"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "盆里盛的是红辣椒炒鸟舌头，红油油的好不炫目。\n");
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
