#include <armor.h>
inherit HEAD;
#include <ansi.h>

void create() {
	set_name(HIW"紫金白玉冠"NOR, ({ "crown" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","一顶非常名贵的紫金白玉冠。");
		set("value", 800);
		set("material", "cloth");
	}
	::init_head();
}
