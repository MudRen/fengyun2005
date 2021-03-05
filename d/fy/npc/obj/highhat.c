#include <armor.h>
inherit HEAD;

void create() {
	set_name("高冠", ({ "hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","一顶白玉黄金高冠，看上去华贵无比，其实只是用普通的材料制成。\n");
		set("value", 800);
		set("material", "cloth");
	}
	::init_head();
}
