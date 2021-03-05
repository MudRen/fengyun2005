
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("玉镯", ({ "jade piece"}) );
	set_weight(58);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个翠绿欲滴的玉手镯\n");
		set("unit", "个");
		set("value", 300);
		set("wear_msg", "$N轻轻地把一个$n戴在手腕上。\n");
		set("unwield_msg", "$N轻轻地把$n从手腕上除了下来。\n");


	}
	::init_wrists();
}

