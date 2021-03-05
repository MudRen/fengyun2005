#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("四品官服", ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件大红镶边的官服，供四品官员穿戴。");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",100);
	}
	::init_cloth();
}
