// tea_leaf.c

#include <weapon.h>
inherit THROWING;
#include <ansi.h>


void create()
{
	set_name(HIC"双翼水晶"NOR, ({ "crystal sand", "magic crystal", "crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一小粒闪着奇异色彩的水晶。\n");
		set("unit", "把");
	        set("base_value", 5000);
		set("base_unit", "粒");
		set("base_weight", 1);
		set("volumn",50);
	}
	set_amount(50);
	::init_throwing(10);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("no_shadow",random(10)+10);
	message_vision("$N中了双翼水晶上的毒！\n", victim);
}

