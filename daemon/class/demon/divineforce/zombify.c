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
		return notify_fail("「空魂异血」只能对战斗中的对手使用。\n");

	if (ANNIE_D->check_buff(target,"cursedflesh"))
		return notify_fail("对方已经受到类似技能的影响了。\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "cursedflesh",
		"att": "curse",
		"name": "破邪心经·空魂异血",
		"time": 30,
		"buff_msg":HIC"\n$n"HIC"面上浮现出青蓝之色，喷出一团腥臭的烟气。\n"HIB"$N"HIB"猝不及防，吸进一口毒雾，登时摇摇欲坠．．．\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/