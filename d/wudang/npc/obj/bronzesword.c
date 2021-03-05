#include <weapon.h>
inherit SWORD;

void create() {
	set_name("小铜剑", ({ "bronze sword","sword" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长剑。\n");
		set_weight(6000);
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(10);
}
