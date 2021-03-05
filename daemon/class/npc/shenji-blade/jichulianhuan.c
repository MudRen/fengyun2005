


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string dodskill,msg;
    	int extra;
    	int tmp,chance;
    	extra = me->query_skill("shenji-blade",1);
    	if ( extra < 50) return notify_fail("你的神机刀法还不够纯熟！\n");
    	dodskill = (string) me->query_skill_mapped("dodge");
    	if ( dodskill != "shenji-steps")
        	return notify_fail("『计出连环』需要神机步法的配合！\n");
    	tmp = me->query_skill("shenji-steps",1);
    	if ( tmp < 50 )return notify_fail("你的『神机步法』还不够纯熟！\n");
	
	chance=(extra+tmp)/2;
	chance=chance<160? 160-chance:0;
	
	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
        	return notify_fail("『计出连环』只能对战斗中的对手使用。\n");
    
    	target->set_temp("no_check_pfm_win",1);
    	me->add_temp("apply/attack",tmp);
    	me->add_temp("apply/damage",extra);
    	msg = HIR  "\n\n$N"HIR"挥出神机刀法中的绝天灭地的一式－－－计－出－连－环－！！\n\n"NOR;
    	message_vision(msg, me, target);
    		
    		msg=HIR"\n论战篇！\n$N"HIR"手中$w"HIR"直劈$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		target->set_temp("skip_damage_record",1);
    	
    	if(chance<random(160))
    	{
    		msg = HIY  "胜战篇！\n$N"HIY"手中$w"+HIY"斜刺$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
    		msg = HIW  "敌战篇！\n$N"HIW"手中$w"+HIW"平削$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{        
    		msg = HIG  "攻战篇！\n$N"HIG"手中$w"+HIG"横砍$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
    		msg = HIM  "混战篇！\n$N"HIM"手中$w"+HIM"狠剁$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{    
        	msg = HIC  "并战篇！\n$N"HIC"手中$w"+HIC"反撩$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    	if(chance<random(160))
    	{       
    		msg = HIB  "败战篇！\n$N"HIB"手中$w"+HIB"划向$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
//  if(chance<random(160))
    	{    
    		msg = HIR  "决战篇！\n$N"HIR"手中$w"+HIR"加紧，旋风般向$n"+HIR"杀去！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	}
    
		me->add_temp("apply/attack",-tmp);
    	me->add_temp("apply/damage",-extra);
		
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

		
    	me->perform_busy(5);
    	
    	return 1;
}
