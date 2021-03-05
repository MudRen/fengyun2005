#include <weapon.h>
inherit BLADE;

void create() {
	set_name("鬼头大刀", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("long", "这是一把强盗常用的鬼头大刀，黑黝黝的很是沉重。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放入刀鞘。\n");
	}
	::init_blade(10);
}
