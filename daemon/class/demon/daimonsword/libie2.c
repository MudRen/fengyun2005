// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, step;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『天地人魔』只能对战斗中的对手使用。\n");
	
	step = 200;
	extra = 200;
	
	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",step);
	me->add_temp("apply/damage",extra);	
	
	msg =  BLU"\n「花开花落两由之」"NOR CYN" － $N的剑势忽缓而不疏，剑意有余而不尽，突然左右虚指，点向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);

    msg =  MAG  "「梦坠空云齿发寒」"NOR CYN" － $N招法一变，剑式浑然，气象森严，好似无边的没顶黑云压向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg =  HIR BLK  "「小楼一夜听春雨」"NOR CYN" － $N长吸一口真气，剑身泛出蒙蒙青气，幻出一片雪色星雨落向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg =  WHT  "「伤心一际画尤难」"NOR CYN" － $N长剑疾然回收，身势圆转，划出一道弯曲的半弧，向$n击去！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
/*        msg =  WHT "凉月写凄情　环竹秋声听倍惨，\n"NOR CYN"$N手中的剑在空中划了一个弯曲的半弧，向无措的$n击去！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg =  WHT "幽魂归缥缈　空庭落寞恨如何？\n"NOR CYN"$N手中的剑在空中划了一个弯曲的半弧，向无措的$n击去！" NOR	;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
*/        me->add_temp("apply/attack",-step);
	me->add_temp("apply/damage",-extra);	
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	return 1;
}
