// annie 7.02.03
// DEATHGRIP - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「万痛聚身」只能对战斗中的对手使用。\n");

	if (ANNIE_D->check_buff(target,"lowresist"))
		return notify_fail("对方已经受到类似技能的影响了。\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "lowresist",
		"att": "curse",
		"buff1":"resistance/kee",
		"buff1_c":-50,
		"name": "破邪心经·万痛聚身",
		"time": 60,
		"buff_msg":HIB"\n$n双手突转青蓝之色，飞旋着在$N背心拍下一个印记。\n$N只觉四肢百骸经脉中如有针刺，奇痛无比．．．\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}

