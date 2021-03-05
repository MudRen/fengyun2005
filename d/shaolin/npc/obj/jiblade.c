// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("戒刀", ({ "jieblade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "iron");
		set("long", "这是一把出家人用的戒刀，刀刃故意很钝。\n");
		set("wield_msg", "$N抽出一把出家人用的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(5);
}
