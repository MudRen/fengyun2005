// xiesword.c : master xie's weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("燕十三的剑", ({ "yan13-sword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一柄漆黑的剑，漆黑的剑柄上，镶着十三粒晶莹的明珠。 \n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(25);


}
