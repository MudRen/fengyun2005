#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "鬼头剑", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把锃亮的大剑。\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 2);
		set("wield_msg", "$N从剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(10);
}

