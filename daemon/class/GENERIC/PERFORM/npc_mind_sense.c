// This pfm is just to simulate mind_sense. making it easier to code NPCs.


#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage, ap, dp;

	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
                   
	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种法术只能对战斗中的对手使用。\n");

	msg = HIC "$N闭目凝神，印堂发出一道金芒射向$n！\n\n" NOR;
	damage = me->query_skill("magic")*3;
	dp = target->query("combat_exp");
	ap = me->query("combat_exp");
	
	if( random(ap *3 )+ap > dp ) {
		damage = damage + random(damage);
		msg +=  HIY "金芒从$p身上透体而过，拖出一条长长的血箭直射到两三丈外的地下！\n" NOR;
		target->receive_damage("kee", damage, me);
		message_vision(msg, me, target);
        	COMBAT_D->report_status(target);
        	COMBAT_D->win_lose_check(me,target,damage);
	} else
		{	msg += HIB"但是被$n躲开了。\n\n"NOR;
			message_vision(msg, me, target);
			}
	me->start_busy(2);
	return 1;
}
