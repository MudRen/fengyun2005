// xiesword.c : master xie's weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("三少爷的剑", ({ "xiesword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把黑鱼皮鞘黄金吞口的长剑，大约有十来斤左右。\n");
		set("value", 40);
		set("material", "steel");
	}
	init_sword(45);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

}
