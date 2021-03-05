#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon;
		int mod;
		
		p_name = "miwujue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『迷雾』只能对战斗中的对手使用。\n");
		
		if (target->is_busy())
			return notify_fail("对方已经在忙乱中了。\n");
			
		mod = COMBAT_D->can_busy(me, target, "yunwu-strike");	
		if (!mod)
			return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
		
		msg = HIR "$N使出云雾掌法中的『十里迷雾』，双掌挥舞，掌影密布，层层击向$n！" NOR;
		message_vision(msg + "\n", me, target);
	
		if (COMBAT_D->do_busy_attack(me, target, "yunwu-strike", "unarmed", 700, mod))
		{
			msg = CYN"$n"NOR CYN"左冲右突不得解脱！\n"NOR;
			message_vision(msg, me, target);
			target->force_busy(3);
			target->set_temp("busy_timer/yunwu-strike",time());
		}
		else
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		
		return 1;
}

