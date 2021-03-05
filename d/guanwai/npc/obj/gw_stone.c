
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("夺魂针", ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"源自唐门的暗器。\n");
		set("unit", "把");
		set("base_unit", "束");
		set("base_weight", 10);
        	set("base_value", 500);
        	set("volumn",200);
	}
	set_amount(200);
	::init_throwing(20);
}
