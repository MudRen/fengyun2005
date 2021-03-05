// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("小石子", ({ "stone", "stone piece" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一块普通的小石子。\n");
		set("unit", "堆");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
		set("stone",1);
		set("volumn",1000);
	}
	set_amount(1000);
	::init_throwing(10);
}
