/*
		"tiandirenmojue":	([
			"e_id":	"tiandirenmo",
			"c_id":	"天地人魔",
			"fixed_atk":	500,
			"fixed_dmg":	300,
			"self_busy":	4,
			"cdt":			180,	// individual_cdt
			"g_cdt":		60,		// global_cdt
			"weapon":		1,
		]),
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg;
		string p_name;
		mapping perform;
		int level, fixed_atk, fixed_dmg;
		
		p_name = "jichulianhuanjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
							
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『计出连环』只能对战斗中的对手使用。\n");
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		fixed_atk = perform["fixed_atk"] * level /139;
		fixed_dmg = (perform["fixed_dmg"]-320)*level/139 + (level -100)*8;
		
//		if (fixed_atk<300)	fixed_atk = 200 + level ;
//		if (fixed_dmg<250)	fixed_dmg = 150 + level;
		
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",fixed_atk);
		me->add_temp("marks/fixed_dmg",fixed_dmg);
		me->set_temp("marks/no_parry_busy_pfm",1);
		me->add_temp("marks/full_hit_damage",1);
		
		target->set_temp("no_check_pfm_win",1);			
		msg = HIR  "\n\n$N"HIR"挥出神机刀法中的绝天灭地的一式－－－计－出－连－环－！！\n"NOR;
    	message_vision(msg, me, target);
    		
    	msg=HIR"论战篇！$N"HIR"手中$w"HIR"直劈$n！" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	target->set_temp("skip_damage_record",1);
    	
    		msg = HIY  "胜战篇！\n$N"HIY"手中$w"+HIY"斜刺$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIW  "敌战篇！\n$N"HIW"手中$w"+HIW"平削$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIG  "攻战篇！\n$N"HIG"手中$w"+HIG"横砍$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIM  "混战篇！\n$N"HIM"手中$w"+HIM"狠剁$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC  "并战篇！\n$N"HIC"手中$w"+HIC"反撩$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIB  "败战篇！\n$N"HIB"手中$w"+HIB"划向$n！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIR  "决战篇！\n$N"HIR"手中$w"+HIR"加紧，旋风般向$n"+HIR"杀去！" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
    	
    	me->delete_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",-fixed_atk);
		me->add_temp("marks/fixed_dmg",-fixed_dmg);
		me->add_temp("marks/full_hit_damage",-1);
    	
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
		me->delete_temp("marks/no_parry_busy_pfm");
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);


//		write("fixed_atk = "+ fixed_atk + " fixed_dmg = "+ fixed_dmg + "\n");
				
		return 1;
}
