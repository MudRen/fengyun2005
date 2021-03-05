// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("古形剑", ({ "sword" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一形式古雅，钢质极纯的好剑。\n");
		set("value", 2);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N从剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(15);
}
