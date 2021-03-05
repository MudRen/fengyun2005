
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
		return notify_fail("「断喉」只能对战斗中的对手使用。\n");
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 60 ) return notify_fail("你的「地狱狼魂爪」不够熟练！\n");
	msg = HIR "$N闪电般和身扑上，双手一前一后急抓$n的咽喉，要把$n的喉管抓断！\n" NOR;
	me->add_temp("apply/damage",extra*2.2);
	me->add_temp("apply/attack",extra*0.8);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*2.2);
        me->add_temp("apply/attack",-extra*0.8);
	me->start_busy(2);
	return 1;
}
