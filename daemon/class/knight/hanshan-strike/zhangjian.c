#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		
	string msg;
	int extra,bonus, exp_bonus;
	
	extra = me->query_skill("hanshan-strike",1) ;
	if( extra < 100) 
		return notify_fail("『掌剑』至少需要100级的寒山掌法！\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『掌剑』只能对战斗中的对手使用。\n");
		
	bonus = extra/4 + F_LEVEL->get_level(me->query("combat_exp"));
			
	message_vision(HIC"白光忽然闪起，$N出剑，以掌为剑，剑气割空，剑势破空，剑劲越空！\n"NOR, me);
	
	me->add_temp("apply/attack", bonus);
	me->add_temp("apply/damage", bonus);
	target->set_temp("no_check_pfm_win",1);
	
	msg = MAG"$N双掌互相交错，突一纵身，双手化掌为剑疾向$n"MAG"削去！" NOR;
	COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
	msg = YEL"$N"YEL"一侧身，一肘撞向$n"YEL"的面门！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	
	if (extra>=100) {
        	msg = WHT"$N"WHT"又一反身，双掌急向$n"WHT"砍去！" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	
	if (extra>=130) {
        	msg = HIR"$N"HIR"左手横胸，右手忽一亮掌，蓄力已久的掌剑破空向$n"HIR"刺去！" NOR;
		me->add_temp("apply/attack", bonus);
		me->add_temp("apply/damage", bonus);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -bonus);
	}
	
    me->add_temp("apply/attack", -bonus);
	me->add_temp("apply/damage", -bonus);
	
	if (objectp(target))	{
		if (target->query_temp("damaged_during_attack")) 
		 COMBAT_D->win_lose_check(me,target,1);
	}
	
	if (objectp(target))	{
		target ->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

		
	if (extra>=130) 
		me->perform_busy(3);
	else 	
		me->perform_busy(2);
			
	return 1;
}
