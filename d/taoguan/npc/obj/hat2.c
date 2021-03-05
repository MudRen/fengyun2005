// hat.c
#include <armor.h>
inherit HEAD;

void create()
{
	set_name("六根清冠", ({ "trimystic hat", "hat" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value", 7000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_head();
}
