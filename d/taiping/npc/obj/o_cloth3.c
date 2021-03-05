#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("侍卫服", ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","这是一件朝廷侍卫穿的制服。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
