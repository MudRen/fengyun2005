// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("yinshe-stick",1)* 2;
	if ( extra < 100) return notify_fail("你的［银蛇棍法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［银蛇出动］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack", extra/2);		me->add_temp("apply/damage", extra/2);
	weapon = me->query_temp("weapon");
	msg = HIR "只见$N舞动手中的"+ weapon->name()+ HIR"，产生道道棍气，侵入$n的体内！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR "$N左手护胸，右手单臂挥动"+ weapon->name()+ HIR"发出呼呼声，划向$n的脸部！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage", -extra/2);
	me->start_busy(2);
	return 1;
}
