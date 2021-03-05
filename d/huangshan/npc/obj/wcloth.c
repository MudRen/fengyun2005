// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"月白小裤褂"NOR, ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一套月白色的小裤褂。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value", 1000);
	}
	::init_cloth();
}
