
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp,flag;
	object weapon;
	mapping buff;
	
	extra = me->query_skill("tempestsword",1) ;
	if (extra < 100) 
		return notify_fail("你的快雨无行剑法不够纯熟！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这一式只能对战斗中的对手使用。\n");
		
	weapon = target->query_temp("weapon");
	myexp  = me->query("combat_exp");
	hisexp = target->query("combat_exp");
	
	if (COMBAT_D->do_busy_attack(me, target, "tempestsword/knockdown", "step", 300, 10)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time())  		
	{
		message_vision(HIG "\n\n$N"HIG"使一式「秋风吹醒英雄梦」，手中"+me->query_temp("weapon")->name()+HIG"如秋风般倾泻而过，将"+ 
		weapon->name()+  HIG"震得冲天而起，\n" NOR, me,target);
		if( weapon->unequip()){ 
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"快雨无行剑法·吹醒英雄梦",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  30,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}			
		flag=1;
	}

	target->set_temp("marks/disarmed",time());

	if (flag == 1)
		msg=HIY"紧接着"HIY"又将$w一抑一转"HIY"，一式「成败起落不关心」凌空刺向$n"HIY"！"NOR;
	else
		msg=HIY"$N"HIY"手中的$w"HIY"一挑，一式势无可避的「成败起落不关心」向$n刺去"HIY"！"NOR;
	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra*2);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);

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
