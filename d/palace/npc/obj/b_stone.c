#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("围棋子", ({ "go piece","piece"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一粒晶莹光滑的围棋子。\n");
		set("unit", "把");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 0);
		set("stone",1);
		set("volumn",500);
	}
	set_amount(500);
	::init_throwing(10);
}
