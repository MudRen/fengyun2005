#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp, timer, duration, i;
	object weapon;
			
	if (ANNIE_D->check_buff(me,"fg-afo-bffy")<1)
		return notify_fail("你学的武功中没有此项特技。\n");
		
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("空手无法使用此特技。\n");
				
	extra = me->query_temp("pfm/fg-afo-bffy");
	
//	write ("extra = " + extra + "\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『八方风雨会中州』只能对战斗中的对手使用。\n");
	
	target->set_temp("no_check_pfm_win",1);
	
    msg = HIR "\n\n$N大喝一声，赫然使出『血战枪法』中的雷霆一击『--八方--风雨--会中州--』\n"NOR;
    message_vision(msg, me, target);
    
    msg=HIR"★休门★\n$N手中$w"+HIR"由缓至快向$n"+HIR"刺来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
    msg = HIR  "★伤门★\n$N挥舞$w"NOR+HIR",化作漫天矛影,当空刺向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★杜门★\n$N将$w"NOR+HIR"灌满真力,硬生生便朝$n"NOR+HIR"砸了过来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★景门★\n但见$N手中$w"NOR+HIR"幻化出千万条银蛇,漫天攒动,扑向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★惊门★\n$N将$w"NOR+HIR"舞得虎虎生风,卷起一波又一波滔天巨浪，飞向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);	
    msg = HIR  "★开门★\n$N奋起神威,手中$w"NOR+HIR"大开大阖,旋风般朝$n"+HIR"袭了过来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★生门★\n$N断喝一声,手中$w"NOR+HIR"迅如奔雷快如电掣,当胸捅向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "★死门★\n$w"NOR+HIW"划出一道超出任何世俗之美的弧线,宛如刀刃般划过$n"NOR+HIW"的面门！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);   
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
 
 	ANNIE_D->debuff(me,"fg-afo-bffy"); 
    me->perform_busy(4);
	return 1;
}
