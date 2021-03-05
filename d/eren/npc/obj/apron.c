#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("围裙", ({ "cloth"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "vine");
		set("long", "一件沾满了油腻的围裙。\n");
		set("value", 1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
