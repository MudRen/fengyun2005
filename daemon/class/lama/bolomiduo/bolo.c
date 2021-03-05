#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("bolomiduo",1);
		cost = 50;
		msg_self = WHT"$N盘坐合掌道：揭谛揭谛，婆萝揭谛，婆萝僧揭谛，菩提萨婆诃。。\n" NOR;
		msg_target = "";
		type = "kee";
		
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}


