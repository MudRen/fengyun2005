// hat.c

#include <armor.h>
inherit HEAD;

void create()
{
	set_name("太极道冠", ({ "taiji hat", "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value", 10000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 10);
	}
        ::init_head();
}
