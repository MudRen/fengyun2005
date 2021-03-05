// annie 7.04.03
// dancing_faery@hotmail.com
// THOUSAND FEATHER:busy + attack

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j,k,l,skill,damage;
	object weapon;
	object * enemy;
	if(!me->is_fighting())
		return notify_fail("「炽翼千羽」只能对战斗中的对手使用。\n");

	skill = me->query_skill("dragonwhip",1);
	if (skill < 50)
		return notify_fail("「炽翼千羽」需要至少50级的龙凤奇翔鞭法。\n");
	weapon = me->query_temp("weapon");

	enemy = me->query_enemy();

	message_vision( HIR "\n$N"HIR"招法骤变，长鞭乍展还收，在空中盘旋飞展，宛如凤凰天翔之姿。
但听一声清啸激扬，凤凰於飞，无数火羽漫天洒落下来。\n\n"NOR,me);

	for(i=0; i<sizeof(enemy); i++)
	{
		l = 0;	// 会有重叠现象发生
		k = 0;

		target = enemy[i];
		for (j=0;j<skill/25;j++)	// 160lv = 6 ,res->175: 7,res->200: 8
		{
			if (random(target->query("combat_exp")* 4) < random(me->query("combat_exp")) )
				l++;	
			else if (random(target->query("combat_exp")) < random(me->query("combat_exp")))
				k += 1+random(200);
			// else... miss.
		}
		message_vision(RED"结果$N"NOR+RED"",target);
		if (l)
		{
			message_vision("穷于闪躲漫天而下的火羽，",target);
			if (target->query_busy() <= l)
				target->force_busy(l);
		}
		if (k)
		{			// maximum 7* 200 = 1400*4 then random
			k *=4;
			message_vision("被"+chinese_number(k)+"根火羽烧到，",target);
			target->receive_damage("kee",k,me);
		}

		if (l || k) {
			message_vision("闹得手忙脚乱！\n\n"NOR,target);
			COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
		} else
			message_vision("轻轻松松的避开了所有的火羽。\n\n"NOR,target);
	}
	
//	if (wizardp(me))
//		tell_object(me,"BUSY:"+l);
				
	me->perform_busy(2+random(2));
	return 1;
}

