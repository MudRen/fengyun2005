#include <armor.h>
inherit HEAD;

void create() {
	set_name("帽子", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value", 0);
		set("material", "cloth");
	}
	::init_head();
}

