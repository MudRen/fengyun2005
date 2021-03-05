
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("大红布袍", ({ "cloth" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件大红的布袍。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
