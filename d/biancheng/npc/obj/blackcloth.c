#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("黑衫", ({ "black cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件黑色的短衫，上面沾了许多泥土。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
