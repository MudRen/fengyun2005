#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "解郁剑", ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把锃亮的宝剑，被它刺中的人就再也不会忧伤了。\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从宝玉剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的宝玉剑鞘。\n");
	}
	::init_sword(20);
}

