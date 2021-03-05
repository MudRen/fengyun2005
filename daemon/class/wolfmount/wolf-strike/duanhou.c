#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int skill, atk, dmg, atk_mez, atk_cont, dmg_cont, mez;

    
    	if (userp(me) && me->query("class")!="wolfmount")
    		return notify_fail("断喉是狼山的绝技。\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
      		||      !target->is_character()
      		||      !me->is_fighting(target) )
			return notify_fail("『断喉』只能对战斗中的对手使用。\n");

    	skill = me->query_skill("wolf-strike",1);
		atk = skill;
		dmg = skill/2 *3;
    	   	
    	if ( target->query_temp("mesmerize")) { 
			msg = HIW "$N闪电般和身扑上，将$n扑倒在地，露出白森森的牙齿一口向$n的咽喉咬去！\n"NOR;
    		dmg = dmg*3;
    		mez = 1;
    	
    	} 	else
			msg = HIR "$N闪电般和身扑上，双手一前一后急抓$n的咽喉，要把$n的喉管抓断！\n" NOR;

		// atk 200, dmg 300 - 900
					
    	me->add_temp("apply/attack",atk);
    	me->add_temp("apply/damage",dmg);

		if (target->query_temp("mesmerize")) {
			me->add_temp("marks/full_hit_damage",1);
			target->add_temp("cant_dodge",1);
			target->add_temp("cant_parry",1);
		}
		
		message_vision(msg, me, target);
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");

		if (mez && target) {
			me->add_temp("marks/full_hit_damage",-1);
			target->add_temp("cant_dodge",-1);
			target->add_temp("cant_parry",-1);
		}
		
    	me->add_temp("apply/attack",-atk);
    	me->add_temp("apply/damage",-dmg);
    	me->perform_busy(2);
    	return 1;
}

