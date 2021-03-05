// silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int step,fist,extra;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［寒天神腿］只能对战斗中的对手使用。\n");
	
	step = me->query_skill("doomsteps",1);
	fist = me->query_skill("doomstrike",1);
	
	if (step< 100) return notify_fail("“寒天神腿”需要100级的寒天神掌和吹血步法。\n");
	if (fist< 100) return notify_fail("“寒天神腿”需要100级的寒天神掌和吹血步法。\n");
	
	me->add_temp("apply/attack", fist);	
	me->add_temp("apply/damage", fist*2);
	msg = HIR  "$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -fist);
	me->add_temp("apply/damage", -fist*2);
	
	me->add_temp("apply/attack", step);	
	me->add_temp("apply/damage",step*2);
	msg = HIR  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
	me->add_temp("apply/attack", -step);
	me->add_temp("apply/damage",-step*2);
	
	if (me->query("class")=="fighter" || !userp(me)) {
		if (me->query_busy()<2) me->start_busy(2); 
	} else {
		if (me->query_busy()<3) me->start_busy(3);
	}
	return 1;
}
