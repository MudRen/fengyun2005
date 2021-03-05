#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("狼头刀", ({ "wolf blade", "blade" }) );
	set("unit", "把");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "这是一把狼山弟子常用的刀，刀刃很锋利。\n");
		set("wield_msg", "$N操起$n握在手里。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("value", 4);
		set("material", "bone");
	}
	::init_blade(15);
}
