#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create() {
	set_name(RED"红缨帽"NOR, ({ "red hat","hat" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","一顶官差们戴的红缨帽。");
		set("value", 8);
		set("material", "cloth");
	}
	::init_head();
}
