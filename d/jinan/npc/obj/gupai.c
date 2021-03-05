
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("鹘牌", ({ "gupai" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一张晶滢剔透的象牙骰牌\n");
		set("unit", "堆");
		set("value", 100);
		set("base_unit", "张");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",48);
	}
	set_amount(48);
	init_throwing(1);
}
