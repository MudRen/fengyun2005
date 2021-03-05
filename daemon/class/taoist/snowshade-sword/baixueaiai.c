#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, power,nd;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『白雪皑皑』只能对战斗中的对手使用。\n");
	
	weapon = me->query_temp("weapon");
	extra = me->query_skill("snowshade-sword",1);
	
	power = 0;
	if (me->query("class")=="taoist" && me->query_skill("scratching")) 
		power=me->query_skill("scratching")/4;

	// 180+125 = 305, 180+125*2 = 430		
	me->add_temp("apply/attack", extra + power);	
	me->add_temp("apply/damage", extra + power*3/2);
	msg = HIW  "$N"HIW"手中的"+ weapon->name() +HIW"撒出漫天飞雪，一道白光象闪电般挥向$n！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra - power);
	me->add_temp("apply/damage", -extra - power*3/2);
	
	me->perform_busy(2);
	return 1;
}
