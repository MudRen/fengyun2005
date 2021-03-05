
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("玉珠花", ({ "jade"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个翠绿欲滴的玉珠花\n");
		set("unit", "个");
		set("value", 10000);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

		set("female_only", 1);

	}
	::init_head();
}

