// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("金锋剑", ({ "golden sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把闪闪发著金光的长剑。\n");
		set("value", 3400);
                set("no_get",1);
                set("no_drop",1);

		set("material", "gold");
	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(30);
}
