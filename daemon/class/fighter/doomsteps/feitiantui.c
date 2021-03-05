// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［飞天腿］只能对战斗中的对手使用。\n");
	
	extra = me->query_skill("doomsteps",1);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage",extra*2);
	msg = HIR  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage",-extra*2);
	if (me->query_busy()<2) 
		me->start_busy(2);
	return 1;
}
