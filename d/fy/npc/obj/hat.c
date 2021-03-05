#include <armor.h>
inherit HEAD;

void create()
{
	set_name("宽大的斗笠", ({ "hat" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long","竹编的斗笠，笠沿很宽大。\n");
		set("value", 100);
		set("material", "wood");
		set("armor_prop/armor", 5);
	}
	::init_head();
}


