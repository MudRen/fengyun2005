// annie 6.27.03
// absorb iron-cloth

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「抱残守缺」只能对战斗中的对手使用。\n");

	if (target->query_temp("buff/no_abs"))
			return notify_fail("对方已经中了「抱残守缺」，还不抓紧时机攻击？\n");

	i = target->query_skill("iron-cloth") + target->query_temp("apply/iron-cloth");
	if (!i)
		return notify_fail("现在没有必要施展「抱残守缺」。\n");

	message_vision( HIC
"\n$N轻轻一按$n手腕，整个人若水蛇般顺势滑进$n怀中。\n"NOR MAG"$N柔若无骨的手拂上$n的胸膛，轻抚着一路滑到小腹丹田。\n" NOR, me,target);
	message_vision( HIW
"$n反应不及，刹那间面如土色，浑身筛糠般狂抖，护身的硬功竟已在这一瞬被$N尽数破去。\n\n" NOR, me,target);

	target->add_temp("buff/no_abs",1);
	me->perform_busy(1);
	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
						 i :), 60);
	return 1;
}

void remove_effect(object me,int amount)
{
	if (!me)	return;
	if (me->query_temp("buff/no_abs")>0)
		me->add_temp("buff/no_abs",-1);
	tell_object(me, "你骨节中的酥软之感渐渐退去了。\n");
}
 
