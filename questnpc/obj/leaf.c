#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("枯黄的叶", ({ "deadleaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long",     "一片枯黄的落叶，衰败而零落。\n");
		set("base_unit", "张");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",5000);
	}
	set_amount(5000);
        ::init_throwing(30);
}
