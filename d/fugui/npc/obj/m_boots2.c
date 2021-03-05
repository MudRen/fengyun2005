// cloth.c
//

#include <armor.h>

inherit BOOTS;
#include <ansi.h>
void create()
{
    set_name(HIC"步云靴"NOR, ({ "cloudboots" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "穿上这步云靴，就是讨个平步青云的吉利。\n");
		set("material", "cloth");
		set("value", 1000);
	}
	::init_boots();
}
