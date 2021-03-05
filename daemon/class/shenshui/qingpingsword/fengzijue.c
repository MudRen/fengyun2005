#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int mod, enhance;
	
	if (userp(me))
		return notify_fail("你使用的武功里没有这个特殊招式。\n");
		
	if(me->query_skill("qingpingsword",1)<50)
		return notify_fail("你的清平剑法等级不够。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「封」字诀只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
	
	mod = COMBAT_D->can_busy(me, target, "qingpingsword");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此剑法迷惑的。\n"NOR);
		
	msg = CYN "$N"+CYN"使出清平剑法中的「封」字诀，连递数个虚招企图扰乱$n"+CYN"的攻势，";
	
	me->perform_busy(1);
	
	enhance = 1500/4;
	if (COMBAT_D->do_busy_attack( me, target, "qingpingsword/fengzijue", "unarmed", enhance, mod))
	{		
		msg += "结果$p"+CYN"被$P"+CYN"攻了个措手不及！\n" NOR;
		target->force_busy((int)me->query_skill("qingpingsword", 1) / 100 + 2);
		target->set_temp("busy_timer/qingpingsword",time());
	} else {
		msg += YEL"可是$p"NOR YEL"看破了$P"NOR YEL"的企图，并没有上当。\n" NOR;
	}
	
	message_vision(msg, me, target);

	return 1;
}
