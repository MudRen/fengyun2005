#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("黑色的丝质长裙", ({ "black skirt","skirt"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "gold");
		set("long", "一件黑色的丝质长裙。\n");
		set("value", 8000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
