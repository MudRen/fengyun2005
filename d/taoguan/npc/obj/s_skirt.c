#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"白色道袍"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "白色道袍，长可及地。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 1000);
	}
	::init_cloth();
}
