#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("黑裤", ({ "pant" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","这是一条灰黑色的大裤衩。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
