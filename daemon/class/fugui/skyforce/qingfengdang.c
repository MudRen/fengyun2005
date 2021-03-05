#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_self = HIG "$N双手十支手指冒出丝丝冷气，瞬间连点自身三十六道大穴....
片刻之后，$N感觉清风拂面，快意盎然，深呼一口气，精神看起来好多了。\n" NOR,
		msg_target = HIG "$N双手十支手指冒出丝丝冷气，瞬间连点$n全身三十六道大穴....
片刻之后，$n感觉清风拂面，快意盎然，深呼一口气，精神看起来好多了。\n" NOR,
		type = "gin";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}

