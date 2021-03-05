#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		if (me->query_skill("qingpingforce",1) < 100)
			return notify_fail("『静心法』需要100级的清平心法。\n");
	
		limit = "self";
		amount = me->query_skill("qingpingforce",1);
		cost = 50;
		msg_self = WHT "$N"NOR+WHT"静气平声，按着清平心法的口诀踏踏实实地打了一套拳法。\n" NOR;
		msg_target = "";
		type = "kee";
			
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}


















