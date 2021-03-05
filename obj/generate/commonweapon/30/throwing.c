

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("铜豌豆", ({ "bean" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
//		set("long",	"飞镖是一种十分常见的暗器。\n");
		set("unit", "堆");
		set("base_unit", "枚");
		set("base_weight", 40);
		set("base_value", 200);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(30);
}
