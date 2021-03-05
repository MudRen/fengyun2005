// Silencer@fengyun	June.2005
//	+atk 85. +dmg 0;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,n;
	
	if (me->query("class") != "shaolin")
		return notify_fail("『反背连环锤』是少林弟子的绝招。\n");
	
	extra = me->query_skill("liuxing-hammer",1);
	if (extra < 50) 
		return notify_fail("『反背连环锤』至少需要５０级的反转流星锤法。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『反背连环锤』只能对战斗中的对手使用。\n");
		
	msg = BBLU+HIY  "$N使出流星锤法中的『反背连环』，假意抽身急退，蓦地反身抖手一锤！\n" NOR;      	
    message_vision(msg, me, target);
    
        	me->add_temp("apply/attack",extra*3/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack",-extra*3/2);
			
	if (extra >= 80) {
		msg = BBLU+HIY  "$N紧跟一招，反身又是一锤！！\n" NOR;
    	message_vision(msg, me, target);
        	me->add_temp("apply/attack",extra*3/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack",-extra*3/2);
    }	
   
   if (extra >= 110) {
        msg = BBLU+HIY  "$N竟然还不回头，两臂一振，再来一锤！\n" NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack",extra*3/2);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->add_temp("apply/attack",-extra*3/2);
	}
        
	me->perform_busy(2);
	return 1;
}
