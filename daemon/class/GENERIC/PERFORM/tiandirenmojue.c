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
		string msg,p_name;
		mapping perform;
		int fixed_atk, fixed_dmg, level;
		
		p_name = "tiandirenmojue";
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
							
							
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『天地人魔』只能对战斗中的对手使用。\n");
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		fixed_atk = perform["fixed_atk"] * level /139;
		fixed_dmg = (perform["fixed_dmg"]-320)*level/139 + (level -100)*8;
				
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",fixed_atk);
		me->add_temp("marks/fixed_dmg",fixed_dmg);
		me->add_temp("marks/full_hit_damage",1);
					
		target->set_temp("no_check_pfm_win",1);
		msg = HIY  "\n$N"HIY"神气贯通，将天地人魔连环八式一气呵成！\n"NOR;
		message_vision(msg, me);
		
		msg = HIY"万魔初醒！" NOR;
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
		target->set_temp("skip_damage_record",1);
        
        msg = HIY  "魔焰万丈！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "魔光乍现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "天魔独尊！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "万刃天魔！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "天魔回天！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "天魔七现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        msg = HIY  "万魔归宗！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"割伤");
        
    	
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
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		
		return 1;
}
