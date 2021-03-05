// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(WHT"承影"NOR, ({ "chengying sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "殷时三名剑之一，此为含光，见剑不见刃，\n黄昏日落之时，以剑指北，日影遍及锋刃，但闻微弱之音，被斩杀者毫无痛楚。\n");
        set("value", 20);
		set("material", "steel");
	}
    ::init_sword(20);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}
