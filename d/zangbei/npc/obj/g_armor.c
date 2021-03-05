#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("链子甲", ({ "chainarmor"}) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "gold");
		set("long", "一件精钢打成的链子甲。\n");
		set("value", 100);
		set("armor_prop/armor", 15);
	}
	::init_cloth();
}
