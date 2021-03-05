#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("九尾火貂皮", ({ "hide"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("long", "一张九尾火貂的貂皮。\n");
		set("value", 200);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
