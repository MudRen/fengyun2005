#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
			
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_target = HIY "$N神情凝重，手掌紧贴$n额头，缓缓将真气渡入$n体内....
片刻之后，$n神色一缓，胸口暖意顿生，有如旭日当空，长吁一口浊气，心神安宁多了。\n"NOR;
		msg_self = HIY "$N神情凝重，一手抚额，真气流转....
片刻之后，$N神色一缓，胸口暖意顿生，有如旭日当空，长吁一口浊气，心神安宁多了。\n" NOR;
		type = "sen";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}