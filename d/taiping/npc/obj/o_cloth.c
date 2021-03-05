#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(RED"官服"NOR, ({ "clothes" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","这是一件大红的七品官服。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
