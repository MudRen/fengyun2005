// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("铁剑", ({ "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把铁剑。\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N从腰中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	::init_sword(20);
}
