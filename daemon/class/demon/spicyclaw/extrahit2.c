#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int num=2,delay=15,i;
	string temp;

	if ( me->query_skill("spicyclaw",1) < (num-1)*50) 
		return notify_fail("『油流麻香式·其"+chinese_number(num,temp)+"』需要"+(num-1)*50+"级的油流麻香手！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『油流麻香式』只能对战斗中的对手使用。\n");

	if (me->query("timer/spicyclaw"+num) + delay > time())
		return notify_fail("『油流麻香式·其"+chinese_number(num,temp)+"』无法连续使用！\n");

	for (i=0;i<num ;i++ )
		if (me->query("timer/spicyclaw"+i) + 1 > time() && (userp(me) && !wizardp(me)))
			return notify_fail("『油流麻香』各式间需要至少一秒的间隔。\n");
	
	target->set_temp("no_check_pfm_win",1);
	target->set_temp("skip_damage_record",1);

	me->set_temp("annie/spicyclaw_perform",num);

	for (i=0;i<num ;i++ )
		COMBAT_D->do_attack(me,target,TYPE_PERFORM);

	me->delete_temp("annie/spicyclaw_perform");

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

		me->set("timer/spicyclaw"+num,time());
	
	
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
