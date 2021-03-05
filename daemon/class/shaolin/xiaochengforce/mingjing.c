#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
	    if(me->query("class")!="shaolin") 
			return notify_fail("只有少林僧人才能使用『明镜』\n");

		limit = "self";
		amount = me->query_skill("xiaochengforce",1);
		cost = 50;
		msg_self = WHT"$N盘坐合掌道：一微尘中入三昧，成就一切微尘定，而彼微尘亦不增，于一普现难思刹。\n" NOR;
		msg_target = "";
		type = "kee";
			
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}
