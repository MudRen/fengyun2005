inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"夜光明珠"NOR, ({ "pearl"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只在黑夜里也能闪闪发光的夜明珠，估计能卖个好价钱。\n");
		set("value", 500);
		set("armor_prop/armor", 0);
		set("thief_obj",1);
	}
	::init_item();
}
