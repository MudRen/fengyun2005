// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("luohan-quan",1);
	if( extra <10) return notify_fail("『雏凤展翅』需要10级罗汉拳！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『雏凤展翅』只能对战斗中的对手使用。\n");
		
	me->add_temp("apply/attack", extra * 2);	
	me->add_temp("apply/damage", extra);
	msg = HIY"$N"HIY"左拳右掌，拳抵掌心，向前一送，忽地拳掌一分，右掌横挡，左掌连挥，
如雏凤展翅，向$n"HIY"击去！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra * 2);
	me->add_temp("apply/damage", -extra);
	
	me->perform_busy(2);
	
	return 1;
}


