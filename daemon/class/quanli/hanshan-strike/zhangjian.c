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
		return notify_fail("［掌剑］只能对战斗中的对手使用。\n");
	extra = me->query_skill("hanshan-strike",1) ;
	if( extra <=60) return notify_fail("你的［寒山掌法］还不够熟练！\n");
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/5);
	msg = HIR  "$N双掌互相交错，突一纵身，双手化掌为剑疾向$n削去！" NOR;
	COMBAT_D->do_attack(me,target,  TYPE_PERFORM,msg);
	msg = HIR  "只见$N反身一肘，撞向$n的面门！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR  "$N又一反身，双掌急向剑$n砍去！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR  "$N左手横胸，右手忽一亮掌，蓄力已久的［掌剑］破空向$n刺去！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/5);
	me->start_busy(4);
	return 1;
}
