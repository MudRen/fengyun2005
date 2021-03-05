#include <weapon.h>
inherit THROWING;
void create()
{
    set_name("落花", ({ "drop flower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "把");
        set("long", "一瓣尚未凋谢的落花，散发出一丝淡淡的香气。\n");
        set("base_unit", "瓣");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	::init_throwing(2);
}
