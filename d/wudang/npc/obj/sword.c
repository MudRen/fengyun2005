// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("青锋剑", ({ "sword" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把专为武当弟子使用的宝剑。\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N从剑鞘中抽出一把闪闪发光的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(15);
}
