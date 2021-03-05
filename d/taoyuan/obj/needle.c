#include <weapon.h>
inherit THROWING;

void create()
{
    set_name("绣花针", ({ "needle" , "skirt needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一根细细尖尖的针。\n");
        set("base_unit", "根");
		set("base_weight", 1);
		set("base_value", 3);
	}
    set_amount(1);
    ::init_throwing(18);
}



