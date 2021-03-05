#include <armor.h>
inherit HEAD;

void create() {
	set_name("大草帽", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","一顶大草帽，上面沾了许多白灰。\n");
		set("value", 8);
		set("material", "cloth");
	}
	::init_head();
}
