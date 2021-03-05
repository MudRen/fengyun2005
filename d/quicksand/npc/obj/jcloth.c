
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白长衫", ({ "cloth" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件雪白的长衫，用名贵的缎料织成。\n");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
