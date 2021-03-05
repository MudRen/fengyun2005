// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("xiruo-blade",1);
	if ( extra < 50) return notify_fail("你的［息若刀法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［八方风雨］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);

	msg =  HIR "$N使出息若刀法中的最具威力的一刀----［八方风雨］，手中的"+ weapon->name()+ HIR "风雨般地砍向$n的双掌！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY "只见$N右手一抖，"+ weapon->name()+ HIY"划向$n的左肩！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg =  HIB "$N凌空一劈，"+ weapon->name()+ HIB"削向$n的右肩！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIC "$N长啸一声，聚功力于左手，使出刀法的最高境界--手刀，朝$n的胸前劈去！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -extra);
	me->start_busy(5);
	return 1;
}
