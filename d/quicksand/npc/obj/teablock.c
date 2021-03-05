
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("茶砖", ({ "teablock" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","关外最畅销的茶砖。\n");
		set("unit", "堆");
		set("base_unit", "块");
		set("base_weight", 5);
		set("base_value", 10);
		set("volumn",7);
	}
	set_amount(7);
	::init_throwing(1);
}
