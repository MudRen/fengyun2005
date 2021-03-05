#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("红短裙", ({ "red skirt","skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件漂亮的小红短裙。");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
