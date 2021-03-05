#include <weapon.h>
inherit SWORD;

void create() {
	set_name("缅剑", ({ "sword"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把锋刃锃亮，质地柔软的长剑。\n");
		set_weight(6000);
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(20);
}
