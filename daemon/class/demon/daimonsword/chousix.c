// 重来云山，愁情盈袖，满目皆秋。——　三叹剑法·愁思烈杀式,annie 6.29.03
// A BUFF SKILL.

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill ;
	object weapon,ob;
	string obn;

	skill = me->query_skill("daimonsword",1);
	if (skill < 180)
		return notify_fail(HIG"『愁思烈杀式』"NOR"至少需要180级三叹剑法。\n");
	
	if (!me->is_fighting())
		return notify_fail(HIG"『愁思烈杀式』"NOR"只能在战斗中使用。\n");
	
	if (me->query_temp("buff/berserk_attack"))
		return notify_fail("你已经在使用类似的武功了。\n");
 	if(me->query_temp("feat"))
	 	if(sizeof(me->query_temp("feat")))
 			return notify_fail("你已经在使用类似的武功了。\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("只有魔教弟子才能施展"HIG"『愁思烈杀式』"NOR"。\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		if (me->query("potential") - me->query("learned_points") < 250)
 			return notify_fail(HIG"『愁思烈杀式』"NOR"极其消耗人的潜能，你的潜力不足，当心油尽灯枯。\n");

		me->add("learned_points",250);	// pay 'potz,snicker	// was 100,increase de 250 for new function 07.01.2003,annie
	}
	
	me->start_busy(1);
	
	weapon = me->query_temp("weapon");
	obn = me->query("marry_name");

	message_vision(MAG "\n一恍惚间，$N似乎又见到了"+ obn + HIG"温柔的面孔，淡然的神色，晶莹的泪珠，清减的笑颜．．\n" NOR, me);
	message_vision(WHT "往昔旧事历历在目，如走马灯般一幕幕的流过$N眼前。\n\n" NOR, me);
	message_vision(RED "$N仰天悲声大啸，双目尽赤，状如疯虎，竟使出一脉拼命打法，奋然抢攻而出。\n" NOR, me);

    me->set_temp("buff/berserk_attack",1);
	me->set_temp("buff/berserk_skill","daimonsword");
	me->set_temp("buff/berserk_attack_msg",MAG"\n$N奋不顾身，不退反进向$n抢去！\n"NOR);
	me->set_temp("feat/chousibuff",1);

	me->set_temp("feat/precision",200);	// double hitrate
	me->set_temp("feat/mighty",200);	// double damage	 ; annie 7.01.2003

	me->set_temp("counter_action_extra",1);
	me->set_temp("counter_msg",MAG"\n$N反身让步向前，回手一剑刺向$n！\n\n"NOR);
	me->add_temp("apply/haste",150);
	me->add_temp("apply/parry",200);
	me->add_temp("apply/dodge",-400);
	me->add_temp("apply/dual_attack",150);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);
	return 1;
}


int remove_effect(object me)
{
	if(!me) return 0;
	me->delete_temp("apply/dual_attack",150);
	me->delete_temp("buff/berserk_attack");
	me->delete_temp("buff/berserk_skill");
	me->delete_temp("buff/berserk_attack_msg");
	me->delete_temp("feat/chousibuff");
	me->delete_temp("counter_action_extra");
	me->delete_temp("feat/precision",200);
	me->delete_temp("feat/mighty",200);
	me->add_temp("apply/haste",-150);
	me->add_temp("apply/parry",-200);
	me->add_temp("apply/dodge",400);
	message_vision(HIY "．．绿芜平寂，逝去的终作水烟，却是再也不能挽回。\n$N渐渐平静下来，眼中露出一丝消抹不去的颓唐。\n" NOR, me);
	me->perform_busy(4);	// busy 4 due lost effect
	return 1;
}
