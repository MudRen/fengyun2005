
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("乌衣", ({ "dark cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("long", "一件乌黑的麻衣。\n");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
