// A perform with extra damage to sen. (up to (200*2 + 150)*3 = 1250 wound

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("spring-blade",1);
	if ( extra < 100) return notify_fail("你的春风快意刀还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIG"风逝云栖"NOR"只能对战斗中的对手使用。\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	target->add_temp("no_check_pfm_win",1);
	 
	msg = HIC "\n$N"HIC"刀势乍然一转，杀气如春雪般消融，手中的"+(me->query_temp("weapon"))->name()+ HIC"化成了一片似有似无
的连绵春色，倒映着青山绿水，碧草蓝天，那么痴迷轻艳的落向$n。\n" NOR;
	
	message_vision(msg, me, target);
		
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	
	if (target)
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIG"$N竟还呆呆的半晌，突然一手捂住胸口，喷出一口鲜血。\n"NOR,target);
		target->receive_wound("sen",COMBAT_D->magic_modifier(me, target, "sen",me->query_skill("blade")*3+1), me);	
	}
	
    if (target) {
    	target->add_temp("no_check_pfm_win",-1);
        COMBAT_D->win_lose_check(me,target,1);
    }
    
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage", -extra);
	
	me->perform_busy(2);
		
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
