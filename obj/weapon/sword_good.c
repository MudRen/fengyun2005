#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "宝剑", ({ "goodsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "宝剑\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N拂拭了一下剑刃，将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(80);
}

