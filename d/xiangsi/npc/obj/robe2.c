#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("深灰长袍", ({ "robe" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件深灰色的长袍。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 1000);
	}
	::init_cloth();
}
