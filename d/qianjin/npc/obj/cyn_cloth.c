// cyn_cloth.c
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(CYN"青布长袍"NOR, ({ "cyan robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件极长的青布长袍。\n");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 6);
	}
	::init_cloth();
}
