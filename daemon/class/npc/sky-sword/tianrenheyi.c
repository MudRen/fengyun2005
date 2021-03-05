// 燕南天南天剑法的绝招“天人合一”
//	hehe, 又一个NPC独有的skill。

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int delay;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("“天人合一”只能对战斗中的对手使用。\n");
		
	if((int) me->query_skill("sky-sword",1) < 200 && userp(me))
		return notify_fail("你的南天剑法还不够精纯，不能发出“天人合一”。\n");
	
	delay=2+random(2);
	message_vision(HIG"$N心神进入止水不波的清明天地。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), delay);
	me->start_busy(5);
	return 1;
}


void kill_him(object me, object target)
{
	int targetexp,damage,mylevel,myexp,targetkee;
	string msg;
	if(me->is_fighting() && target->is_fighting() && environment(me) == environment(target))
	{
		msg = HIY "\n$N似醒还醉的双眼倏地睁亮，爆出无可形拟的精芒，赫然使出天地变色的一招「天人合一」，
长剑化作万道长虹，有若脱弦之箭游龙破浪般射向$n的心口！" ;
		targetexp=target->query("combat_exp");
		myexp=me->query("combat_exp");
		mylevel=me->query_skill("sky-sword", 1)/2;
		targetkee=target->query("max_kee");
	
		damage=targetkee*(75+random(mylevel))/100;
		if(random(myexp*2+targetexp)>targetexp)
			msg += HIR "\n$n只觉身上一凉，$N的剑气已经透体而入。\n" NOR;
		else {
			msg+=HIR "\n$n就地一滚，非常狼狈的躲过了$N的这一剑，但却无法躲过漫天的剑气。\n"NOR;
			damage=damage/2;
	     	}
		target->receive_wound("kee",damage, me);
		message_vision(msg, me, target);
        	target->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(target);
		target->set_temp("last_damage_from",me);
	}
	me->start_busy(1);
	return ;
}
