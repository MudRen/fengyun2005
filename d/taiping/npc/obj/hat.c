
#include <armor.h>
inherit HEAD;

void create() {
	set_name("大毡帽", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","一顶大毡帽，戴在头上就像顶了个小伞。\n");
		set("value", 8);
		set("material", "cloth");
	}
	::init_head();
}
