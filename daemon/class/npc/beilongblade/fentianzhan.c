
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string dodskill,msg;
	int extra, busy,busy2,pp=0,pd=0;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『分天斩』只能对战斗中的对手使用。\n");

	if (me->query_skill("beilongblade",1) < 135)
		return notify_fail("你对悲龙刀法掌握不足，无法使用『分天斩』。\n");
	
	extra = me->query_skill("blade");

	pp=random(random(extra*6))+1;
	pd=random(random(random(extra*12)))+1;
	// 极不稳定……极小机会出现超高伤害。
	me->add_temp("apply/attack",pp);
	me->add_temp("apply/damage",pd);	

	msg =  HIW"$N平抬"+(me->query_weapon())->name()+HIW"过肩，侧身半跪，猛然一声断喝，震得$n"HIW"耳鼓鸣动，眼冒金星，脚下为之一顿。\n"HIR"$N"HIR"趁势长身纵起，凌$n"HIR"於一丈之上，挟风雷之气作出分天一击！\n" NOR;
	message_vision(msg, me, target);
	
    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");

	me->add_temp("apply/attack",-pp);
	me->add_temp("apply/damage",-pd);	

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
