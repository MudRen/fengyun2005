// 重来云山，愁情盈袖，满目皆秋。——　三叹剑法·愁思烈杀式,annie 6.29.03
// A DEBUFF SKILL.

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill,dmg;
	object weapon,ob;
	string obn;

	skill = me->query_skill("daimonsword",1);
	if (skill < 180)
		return notify_fail(HIG"『愁思烈杀式』"NOR"至少需要180级三叹剑法。\n");
	
	if (!me->is_fighting())
		return notify_fail(HIG"『愁思烈杀式』"NOR"只能在战斗中使用。\n");
	
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

	weapon=me->query_temp("left_hand");
	if (!weapon)
		weapon=me->query_weapon();
	message_vision(HIW"\n$N"HIW"形如鬼魅般飘近$n"HIW"身前，莹白如玉的手腕向$n"HIW"胸前探去．．．
"HIG"$n"HIG"大惊失色，连忙收招封住$N"HIG"手腕，却不料$N"HIG"左手"+weapon->name()+HIG"已经自三焦脉上直刺而下。\n" NOR, me, target);

	dmg=ANNIE_D->debuff(target,"all",1);
	if (dmg)
	{
		dmg = COMBAT_D->magic_modifier(me, target, "kee", dmg*1000);
		target->receive_damage("kee",dmg,me);
		target->receive_wound("kee",dmg,me);
	    COMBAT_D->report_status(target);
	}
	me->perform_busy(1);
	return 1;
}

