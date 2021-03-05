#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("玻璃弹子", ({ "ball"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"小孩玩儿的玻璃弹子，五颜六色十分漂亮。\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
	}
	set_amount(1);
	init_throwing(10);
}
