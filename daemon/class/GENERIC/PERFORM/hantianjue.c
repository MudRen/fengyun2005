#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon;
		int level, fixed_atk, fixed_dmg;
				
		p_name = "hantianjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『寒天』只能对战斗中的对手使用。\n");
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		fixed_atk = perform["fixed_atk"] * level /139;
		fixed_dmg = (perform["fixed_dmg"]-320)*level/139 + (level -100)*8;
		
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",fixed_atk);
		me->add_temp("marks/fixed_dmg",fixed_dmg);
		
		target->set_temp("no_check_pfm_win",1);
		msg = HIR  "$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！\n" NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"","瘀伤");
		target->set_temp("skip_damage_record",1);
        
		msg = HIR  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！\n" NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"","瘀伤");
        
    	me->delete_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",-fixed_atk);
		me->add_temp("marks/fixed_dmg",-fixed_dmg);
		
       	if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}

