
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("老羊皮背心", ({ "furcloth" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件老羊皮背心，已经有年头了。\n");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
