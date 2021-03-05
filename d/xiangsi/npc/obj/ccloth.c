#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("笔挺青衫", ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件笔挺挺的青色衣衫。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 2000);
	}
	::init_cloth();
}
