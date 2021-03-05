// cloth.c
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"金甲"NOR, ({ "golden armor", "armor", "cloth" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是金色的盔甲。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
