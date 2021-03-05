#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("豹皮", ({ "hide"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("long", "一件用野兽皮做成的遮体之物。\n");
		set("value", 2000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
