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
		return notify_fail("「溃散溢体」只能对战斗中的对手使用。\n");

	if (ANNIE_D->check_buff(target,"lowresist"))
		return notify_fail("对方已经受到类似技能的影响了。\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "lowresist",
		"att": "curse",
		"buff1":"resistance/kee",
		"buff1_c":-100,
		"name": "破邪心经·溃散溢体",
		"time": 60,
		"buff_msg":HIB"\n$n面上浮现出青蓝之色，喷出一团腥臭的烟气。\n$N猝不及防，吸进一口毒雾，登时只觉天旋地转，手脚发麻．．．\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}

