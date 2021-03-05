#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("鸡骨头", ({ "bone", "chicken bone" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一块普通的鸡骨头。\n");
		set("unit", "堆");
		set("base_unit", "块");
		set("base_weight", 1);
		set("base_value", 1);
//		set("stone",1);
		set("volumn",3);
	}
	set_amount(3);
	::init_throwing(20);
}
