

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("断息银针", ({ "needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
//		set("long",	"飞镖是一种十分常见的暗器。\n");
		set("unit", "堆");
		set("base_unit", "枚");
		set("base_weight", 40);
		set("base_value", 3000);
		set("weapon_prop/attack",30);
		set("level_required",50);
		set("volumn",120);
	}
	set_amount(120);
	::init_throwing(60);
}
