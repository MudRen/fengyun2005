// annie 7.02.03
// MANABURST - NPC ONLY

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
		return notify_fail("「万象破灭」只能对战斗中的对手使用。\n");

	if (!target->query("force") && !target->query("mana") && !target->query("atman") )
		return notify_fail("「万象破灭」无法对对方使用。\n");

	message_vision( HIB"\n$N暗运玄功，双掌比着$n缓缓分开，空气里传来一阵仿佛水开似的滋啦声响。\n"NOR,me,target);
	message_vision( HIW
"$n身边紫气升腾，只觉得仿佛整个人都被抽空一般，哇的喷出一口鲜血。\n" NOR, me,target);
	
	target->receive_damage("kee",target->query("force")*(1+random(3)),me);
	target->receive_wound("kee",target->query("force")*(1+random(3))/3,me);
	target->receive_damage("kee",target->query("mana")*(1+random(3)),me);
	target->receive_wound("kee",target->query("mana")*(1+random(3))/3,me);
	target->receive_damage("kee",target->query("atman")*(1+random(3)),me);
	target->receive_wound("kee",target->query("atman")*(1+random(3))/3,me);
	target->set("force",0);
	target->set("mana",0);
	target->set("atman",0);
    COMBAT_D->report_status(target);
	me->perform_busy(2);
	return 1;
}

