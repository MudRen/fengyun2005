// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("西戎利剑", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "边疆诸国人士常用的宝剑，比起中原的剑么刚硬很多。\n");
        set("value", 500000);
		set("material", "steel");
	}
    ::init_sword(20);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}
