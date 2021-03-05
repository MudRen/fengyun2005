// battle_armor.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("可程式战斗装甲", ({ "battle armor <P>", "armor" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "gold");
		set("value", 9000);
		set("no_get",1);
		set("no_drop",1);
		set("armor_prop/armor", 5);

	}
	::init_cloth();
}
