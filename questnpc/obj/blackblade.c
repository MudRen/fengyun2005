#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("漆黑的刀", ({ "black blade", "blade" }) );
	set_weight(15000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "把");
	    set("value", 2000);
	    set("max_enchant",6);
	    set("material", "steel");
	    set("long", 
		"一柄形状很奇特的刀，刀鞘漆黑，刀柄漆黑。\n");
	    set("wield_msg", "$N从漆黑的刀鞘中抽出一把$n\n");
	    set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_blade(40);
}
