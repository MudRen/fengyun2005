#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create() {
	set_name("黄丝带", ({ "ribbon"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "尺许长的黄丝带。\n");
		set("unit", "条");
		set("value", 50);
		set("wear_msg", "$N轻轻地把一条$n系在手腕上。\n");
		set("unequip_msg", "$N轻轻地把$n从手腕上解了下来。\n");
	}
	::init_wrists();
}

