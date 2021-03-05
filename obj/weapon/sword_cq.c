#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( CYN"无形剑气"NOR, ({ "forcesword" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "缕缕");
		set("long", "剑道臻悟，凝气即为利剑。\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 1000);
		set("wield_msg", "$N凝气掌间，$n电射而出，你只觉剑风掠过，割肤如刀。\n");
		set("unwield_msg", "$n在$N手中一闪而逝。\n");
	}
	::init_sword(110);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;
	badint = 
	victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth") * 2  ;
	badint += badint /(2+ random(3));
	if( badint && !random(3)){
	 message_vision( HIC "$N内力凝聚，丝丝剑气透指而出，直取$n的气门！\n"NOR,me,victim);
	}
	else badint = badint/5;
        return badint;
}