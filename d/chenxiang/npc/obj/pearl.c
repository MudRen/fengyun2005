// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("蛇珠", ({ "snake pearl"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个又大又亮的蛇珠。\n");
		set("unit", "个");
		set("value", 1);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");


	}
	::init_head();
}

