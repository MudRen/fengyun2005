// TIE@FY3
#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("银丸", ({ "ball", "silver ball" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一粒拇指大小的银丸。\n");
		set("unit", "堆");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",1000);
	}
	set_amount(1000);
	::init_throwing(10);
}
