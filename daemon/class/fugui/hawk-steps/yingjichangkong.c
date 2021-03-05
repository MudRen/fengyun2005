// yingjichangkong: enhance = 260--> choose a fixed value to make it simple.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int extra, enhance, mod;
	string msg;
	
	if (userp(me))
		return notify_fail("你学的武功中没有这项特技。\n");
		
	if(me->query("class") != "fugui" && userp(me))
		return notify_fail("『鹰击长空』是富贵山庄的绝技。\n");
		
	extra = me->query_skill("hawk-steps",1);
	if ( userp(me) && extra < 50) 
		return notify_fail("『鹰击长空』需要50级鲲鹏步法！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『鹰击长空』只能对战斗中的对手使用。\n");
	   
	mod = COMBAT_D->can_busy(me, target, "hawk-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
	
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
			
   	message_vision( BRED + HIW "$N"+ BRED + HIW"腾身而起，身形有若鹰翔九天，翩若惊鸿！\n"NOR,me,target);
    			
    	if (COMBAT_D->do_busy_attack( me, target, "hawk-steps/yingjichangkong", "step", 260,mod))
    	{
	    	message_vision(HIB"$N"+HIB"仰首一望，不由心神俱失，呆若木鸡，竟已忘了自己尚身处险境！\n"NOR,target);
		target->force_busy(2+random(2));
		target->set_temp("busy_timer/hawk-steps",time());
	}
	else{
	    	msg = YEL"可惜$N"+ YEL"看出了$n"+ YEL"的破绽，借机发动攻势！！"NOR;
	        COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
		me->perform_busy(2);	
	}
	return 1;
}


