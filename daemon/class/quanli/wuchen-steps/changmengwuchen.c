// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("wuchenforce",1);
	if ( extra < 50) return notify_fail("你的［无尘心法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［长梦无尘］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经忙乱失措！\n");

	message_vision( HIY "$N脚踏八方，目视四周，如入无人之境！\n" NOR ,me,target);

	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")/2)

	{
	message_vision( HIW "结果$N被迷得不知方向！\n" NOR,target);
	target->start_busy(2);
	}

	else{
	message_vision( HIW "可惜$n看出了$N的无尘步，向$N迅然攻击！\n" NOR,me,target);
	COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);	
	}
	return 1;
}
