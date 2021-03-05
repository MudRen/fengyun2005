#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"弦月短刀"NOR, ({ "newmoon blade", "blade"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "柄");
		set("long", "一柄弯弯的短刀，形如上弦新月，此刀据说对铁雪的兵刃有些克制效果（20%几率额外伤害）\n");
		set("material", "iron");
		set("value",10);
		set("lore", 1);
	}
	::init_blade(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	mixed c;
	int badint=0;
	if(damage_bonus < 300 ) return 0;
	
	if (!random(5)) return 0;
			
	if(victim->query_temp("weapon") && victim->query_skill_mapped("blade") == "shortsong-blade")
	{
		if ((victim->query_temp("weapon"))->query("skill_type") == "blade")
		{
			badint = victim->query_skill("blade");
			victim->receive_wound("kee",badint*2,me);
			c = HIW"弦月短刀"HIC"划出一道弯曲奇异的弧线，切入了$n的破绽之中。\n" NOR;
		}
	}
	if(victim->query_temp("weapon") && victim->query_skill_mapped("sword") == "diesword")
	{
		if ((victim->query_temp("weapon"))->query("skill_type") == "sword")
		{
			badint = victim->query_skill("sword");
			c = HIW"弦月短刀"HIC"划出一道弯曲奇异的弧线，切入了$n的破绽之中。\n" NOR;
			victim->receive_wound("kee",badint*2,me);
		}
	}
	
	return c;
}
