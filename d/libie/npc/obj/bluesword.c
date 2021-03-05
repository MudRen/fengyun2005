#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("蓝山古剑", ({ "bluesword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把造型古雅的宝剑，剑刃隐隐泛出蓝光。\n");
		set("value", 3);
		set("nodrop_weapon",1);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(10);
}

