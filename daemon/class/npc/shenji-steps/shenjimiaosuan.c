// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	extra = me->query_skill("shenji-steps",1);
	if ( userp(me) && extra < 100) 
		return notify_fail("『神机妙算』需要100级的神机步法。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『神机妙算』只能对战斗中的对手使用。\n");
		
	mod = COMBAT_D->can_busy(me, target, "shenji-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
		
	message_vision(HIG"\n$N"+HIG"身形如闪电，紧紧贴在$n"+HIG"的身后，$n"+HIG"的一举一动，皆在$N"+HIG"的算计之中！\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "shenji-steps/shenjimiaosuan", "step", 300, mod))
	{
		message_vision(HIB"结果$N"+HIB"被攻得大惊失色，手忙脚乱！\n\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/shenji-steps",time());
	}
	else{
		message_vision(HIY"但是$N"+HIY"并不慌张！\n"NOR,target);
		me->perform_busy(2);
	}
	return 1;
}
