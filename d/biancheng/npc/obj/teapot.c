#include <weapon.h>
inherit HAMMER;
inherit F_LIQUID;

void create() {
	set_name("大茶壶", ({ "teapot" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把沉重的大茶壶，没有几把力气是拎不起来的。\n");
		set("value", 100);
		set("material", "earth");
		set("max_liquid", 10);
		set("wield_msg", "$N拿出一把$n，试了试重量，然後托在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	set("liquid", ([
		"name": "茶水",
		"remaining": 10,
	]) );
	::init_hammer(10);
}
