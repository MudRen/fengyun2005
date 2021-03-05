// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("jindian-fire",1)* 2;
	if ( extra < 100) return notify_fail("你的［金殿纵火法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［三昧真火］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/5);

	msg = HIM  "$N双手分胸，一招［三昧真火］纵出一朵火花飞向$n！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIM  "$N双手一合，打出第二道真火！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIM  "$N一手指天，一手向$n一挥，手心又飞出一团烈火！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra/5);
	me->add_temp("apply/damage", -extra/5);
	me->start_busy(3);
	return 1;
}
