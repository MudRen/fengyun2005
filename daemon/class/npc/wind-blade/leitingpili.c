// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［雷霆霹雳］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("wind-blade",1);
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*3);
	msg = HIR  "$N手中的"+ weapon->name() +HIR"幻出漫天刀云，"+weapon->name() +HIR"划破刀云，雷霆霹雳般的击向$n！\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*3);
	me->perform_busy(2);
	return 1;
}
