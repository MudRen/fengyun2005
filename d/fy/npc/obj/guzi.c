
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("鹘子", ({ "guzi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一颗晶滢剔透的象牙骰子。\n");
		set("unit", "堆");
		set("value", 100);
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",100);
	}
	set_amount(100);
	::init_throwing(40);
}
