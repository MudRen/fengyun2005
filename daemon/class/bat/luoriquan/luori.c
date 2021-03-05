#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 	string msg;
 	int extra;
 	
 	extra = me->query_skill("unarmed");
 	if (me->query_skill("luoriquan",1) < 220 && userp(me)) 
 		return notify_fail("落日拳法需要220级落日神拳！\n");
 	
 	if( !target ) target = offensive_target(me);
 	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
		return notify_fail("『落日』只能对战斗中的对手使用。\n");
	
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra/5);
	target->set_temp("no_check_pfm_win",1);
	
	msg = HIR  "\n$N仰天发出一声长笑，使出落日神拳中的『落日』，\n就似灿烂无比的夕阳，顿时间天地亦为之变色！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC    " 长\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        target->set_temp("skip_damage_record",1);
        
        
        msg = HIY  "          河\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "                    落\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	msg = HIR   "                             日\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	msg = HIB   "                                       圆\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/5);

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	
	me->perform_busy(3);
	return 1;
}
