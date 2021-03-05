#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create() {
	set_name(BLU"七星针"NOR, ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"律香川的暗器，据说中后无药可救。\n");
		set("unit", "把");
		set("base_unit", "根");
		set("base_weight", 40);
		set("base_value", 1);
		set("volumn",80);
	}
	set_amount(80);
	::init_throwing(85);
}
