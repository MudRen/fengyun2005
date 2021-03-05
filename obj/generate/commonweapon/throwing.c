

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("飞镖", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"飞镖是一种十分常见的暗器。\n");
		set("unit", "捆");
		set("base_unit", "枝");
		set("base_weight", 40);
		set("base_value", 2);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(10);
}
