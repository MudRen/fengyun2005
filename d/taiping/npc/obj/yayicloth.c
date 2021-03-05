#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("公差服", ({ "yayi cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是驿站的驿吏穿的号服。");
		set("material", "cloth");
		set("armor_prop/armor", 0);
	}
	::init_cloth();
}
