// hat.c
#include <armor.h>
inherit HEAD;

void create()
{
	set_name("黄色道冠", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value", 100);
		set("long", "一顶黄色道冠\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_head();
}
