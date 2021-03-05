#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("绿裙子", ({ "green skirt","skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件漂亮的绿短裙。");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
