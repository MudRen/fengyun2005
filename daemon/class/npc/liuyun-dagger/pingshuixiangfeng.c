// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("yuping-dagger",1);
	if ( extra < 70) return notify_fail("你的［玉平短兵刃］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［萍水相逢］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/attack", extra/10);
	msg = HIW "$N大喝一声：----萍----水----相----逢----！\n" + HIR "萍---手中的" + weapon->name() + HIR "如灵蛇般的向$n砍去！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIR "水---只见"+ weapon->name()+ HIR "似有灵性，划向$n的左肩！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
     	msg = HIR "相---$N凌空一劈，"+ weapon->name()+ HIR "火光四起，削向$n的胸口！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
   	msg = HIR "逢---$N图穷匕现，居高临下，手中"+ weapon->name()+ HIR "朝$n的大腿劈去！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -extra);
	me->add_temp("apply/attack", -extra/10);
	me->start_busy(4);
	return 1;
}
