
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("藏香", ({ "perfume" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","关外藏东产的最畅销的藏香。\n");
		set("unit", "堆");
		set("base_unit", "块");
		set("base_weight", 3);
		set("base_value", 2);
		set("volumn",5);
	}
	set_amount(5);
	::init_throwing(1);
}
