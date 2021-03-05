// annie 7.02.03
// LOBOTOMY - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	
	
	if (userp(me))
	if (!wizardp(me))
		return notify_fail("你不会这样技能。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「魂神飞离」只能对战斗中的对手使用。\n");
	
	if (ANNIE_D->check_buff(target,"idiot"))
		return notify_fail("对方已经受到类似技能的影响了。\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "idiot",
		"att": "curse",
		"buff1":"disable_inputs",
		"buff1_c":1,
		"disable_type":NOR CYN " <魂神飞离>" NOR,
		"name": "破邪心经·魂神飞离",
		"time": 16,
		"buff_msg":HIG"\n$n"HIG"双手拢在胸口，星眸半闭，螓首微抬，望天空低声祝祷．．．\n"BLU"$N"BLU"魂神一震，只觉七魄离体，心中所念竟是不能及身。\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(3);
	return 1;
}

