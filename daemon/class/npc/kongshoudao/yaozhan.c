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
		return notify_fail("［腰斩］只能对战斗中的对手使用。\n");
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 80 ) return notify_fail("你的［空手道］不够熟练！\n");
	msg = HIR "$N"HIR"突然绕到$n"HIR"身后，右膝猛然上顶，双手同时抓向$n"HIR"，企图将$n"HIR"的后腰磕断！" NOR;
	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
	me->start_busy(2);
	return 1;
}
