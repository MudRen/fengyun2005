inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"断肠草"NOR, ({ "duancao", "cao" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",  "一根" + HIR "剧毒"NOR +"的断肠草\n" );
		set("unit", "根");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object me;
	me = this_player();
	me->apply_condition("no_shadow",10);
	destruct(this_object());
        return 1;
}
