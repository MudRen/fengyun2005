#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("灰白色的长袍", ({ "white cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件白色的长袍，上面沾了许多泥土，还有一股难闻的味道。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
