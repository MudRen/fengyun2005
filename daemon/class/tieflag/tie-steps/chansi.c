// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
	string msg;
	mapping buff;
	
	skill = me->query_skill("tie-steps", 1);
	if(skill < 150 && userp(me)) 
		return notify_fail("『缠丝势』需要150级铁血十二势！\n"); 
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『缠丝势』只能对战斗中的对手使用。\n");
		
        if( (int)me->query("force") < 100 )    
        	return notify_fail("你的内力不够。\n");
        if (userp(me))	me->add("force", -100);
        		
        if( ANNIE_D->check_buff(target, "defdown")) 
        	return notify_fail("对方的防御力已经下降了。\n");
        
        skill = skill;
        
        message_vision(HIR "$N"+HIR"轻身一跃，身形犹如陀螺般绕着$n"+HIR"滴溜溜地转个不停。\n" NOR, me,target);	
       	if (COMBAT_D->do_busy_attack(me, target, "tie-steps/chansi", "unarmed", skill*5/2,10))
       	{
       	   	msg = HIR"$N的身形受$n的影响，变的生硬起来！\n"NOR;
        	buff =
			([
				"caster":me,
				"who":	target,
				"type": "defdown",
				"att":"curse",
				"name":"铁血十二势·缠丝势",
				"buff1":"apply/dodge",
				"buff1_c": -skill,
				"buff2":"apply/parry",
				"buff2_c": -skill,
				"time": 60,
				"buff_msg": msg,
			]);
		ANNIE_D->buffup(buff);
	}
	else
	{
		msg = WHT"可惜$N"+WHT"看出了$n"+WHT"的身法，向$n"+WHT"迅然攻击！"NOR;
		COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);	
	}
    return 1;
}
