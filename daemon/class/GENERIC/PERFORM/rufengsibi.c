#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
		string msg;
    	int i, cost, mod,n;
	
		if (me->query_skill("liangyi-force")<100)
			return notify_fail("『如封似闭』需要至少100级两仪心法。\n");
	
		if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("『如封似闭』只能对战斗中的对手使用。\n");

    	if( target->is_busy() )
        	return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
    
    	mod = COMBAT_D->can_busy(me, target, "liangyi-force");	
		if (!mod)
			return notify_fail(HIW"此人功力深湛，不会被此掌法迷惑的。\n"NOR);
    	
    	if (me->query("force")<300)
			return notify_fail("『如封似闭』需要300点的内力为基础。\n");
	
		cost = 250 - me->query_skill("liangyi-force",1);
		if (cost <50) cost = 50;
		if (userp(me)) 
			me->add("force", -cost);
		
    	message_vision(BRED + HIW"\n$N"BRED + HIW"使出两仪心法中一招『如封似闭』，右脚实，左脚虚，粘连粘随，
左掌搭住"+"$n"+BRED + HIW"右腕，横劲发出。\n"NOR, me, target);
    	me->perform_busy(1);   	
    	    	
    	if (COMBAT_D->do_busy_attack(me, target, "liangyi-force/rufengsibi", "step", 200, mod))
    	{
			message_vision(CYN"\n$N"+CYN"身不由主的向前一冲，跌出两步，方始站定！\n\n"NOR,target);
			target->perform_busy(2);
      		target->set_temp("busy_timer/liangyi-force",time());
      	} else 
      		message_vision(WHT"\n可是"+"$n"+WHT"看破了"+"$N"+WHT"的企图，并没有上当。\n\n"NOR, me, target);
			
  		return 1;
}
