#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("供香", ({ "incense" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","藏东产的最畅销的藏香。\n");
		set("unit", "束");
		set("base_unit", "支");
		set("base_weight", 3);
		set("base_value", 200);
		set("volumn",2);
	}
	set_amount(2);
	::init_throwing(1);
}
