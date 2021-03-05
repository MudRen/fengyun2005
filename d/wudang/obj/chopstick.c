#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("竹筷子", ({ "chopstick" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "枝");
                set("unit", "些");
		set("long", "一对吃饭用的竹筷子。\n");
		set("base_weight", 40);
		set("value", 5);
		set("volumn",2);
	}
	set_amount(2);
	::init_throwing(2);
}
