#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_self = WHT"$N体内真气流转，..
片刻之后，$N头顶冒出丝丝白气，深呼一口气，心头有如碧空一洗，脸色看起来红润多了。。\n" NOR;
		msg_target = WHT"$N体内真气流转，双掌紧贴$n背心，缓缓地用内力助$n疗伤....
片刻之后，$N头顶冒出丝丝白气，$n深呼一口气，心头有如碧空一洗，脸色看起来红润多了。\n"NOR;
		type = "kee";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}