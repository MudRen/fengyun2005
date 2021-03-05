#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("金花", ({ "golden flower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long",	"一朵黄金打造的珠花\n");
		set("unit", "堆");
		set("base_unit", "朵");
		set("base_weight", 50);
		set("base_value", 2);
		set("volumn",12);
	}
	set_amount(12);
	::init_throwing(15);
}
