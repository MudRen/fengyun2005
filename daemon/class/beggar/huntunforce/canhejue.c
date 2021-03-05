#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("huntunforce",1);
		cost = 50;
		msg_self = WHT"$N呼吸由低而响，愈来愈是粗重，哇地吐出一口瘀血，脸色看起来好多了。\n" NOR;
		msg_target = "";
		type = "kee";
		
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}