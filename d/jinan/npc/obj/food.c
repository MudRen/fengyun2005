inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(RED"斜阳倚翠红袖招"NOR, ({ "food" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一盘精心烹制的美味佳肴，香气四溢，红花绿叶伴斜阳，十分精致诱人。\n");
		set("unit", "盘");
		set("value", 2000);
		set("food_remaining", 10);
		set("food_supply", 50);
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
