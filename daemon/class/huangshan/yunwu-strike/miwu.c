// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int lvl, mod;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『十里迷雾』只能对战斗中的对手使用。\n");
	
	mod = COMBAT_D->can_busy(me, target, "yunwu-strike");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
		
	lvl = (int) me->query_skill("unarmed") / 30 + 1;
	
	msg = HIR "$N使出云雾掌法中的『十里迷雾』，双掌挥舞，掌影密布，层层击向$n！" NOR;
	message_vision(msg + "\n", me, target);
	
	if (COMBAT_D->do_busy_attack(me, target, "yunwu-strike", "unarmed", lvl* 100, mod))
	{
		msg = CYN"$n"NOR CYN"左冲右突不得解脱！\n"NOR;
		message_vision(msg, me, target);
		target->force_busy(3+lvl/50);
		target->set_temp("busy_timer/yunwu-strike",time());
	}
	else
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		
	me->perform_busy(2);
	return 1;
}
