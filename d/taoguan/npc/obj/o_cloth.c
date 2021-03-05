#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"新道服"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "一件崭新的三清道服。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 100);
	}
	::init_cloth();
}
