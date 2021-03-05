#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
	int skill,duration,duration2;
	string msg;
	mapping buff;
	int extra,my_exp,his_exp;
	int mod;

	if (me->query("class") != "moon")
		return notify_fail("只有皓月宫中人才能施展『阴陵扣命』。\n");

	extra = me->query_skill("snowforce",1);		
	if (extra < 160 && userp(me))
		return notify_fail("『阴陵扣命』需要至少160级的冷雪心经。\n");

	if( !target ) target = offensive_target(me);
	if( target == me) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『阴陵扣命』只能对战斗中的对手使用。\n");

	if (ANNIE_D->check_buff(target,"soft_damage"))
       	return notify_fail("对方已经受到了相似的影响。\n");

	mod = COMBAT_D->can_busy(me, target, "snowforce");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，贸用此招恐非敌手。\n"NOR);

	msg = CYN "\n忽似春临大地，万物融舒，一阵温软的柔风拂过，暖洋洋的慵懒浸进了$N。\n"NOR;
	message_vision(msg,target);
	
	duration2 = 20 + F_ABILITY->check_ability(me,"ylkm_add"); 
	
	if (!COMBAT_D->do_busy_attack( me, target, "snowforce/yinlingkouming","step", 200, mod))
	{
		msg = YEL "$N"NOR+YEL"浑身一震，用力在手背掐下，在疼痛中清醒过来。\n"NOR;
		message_vision(msg,target);
	}
	else
	{
    	msg = WHT "$N"WHT"睡意连绵，打了一个悠长的呵欠，手脚发软，酥麻无力。\n\n" NOR;

    	buff =
		([
			"caster":me,
			"who": target,
			"type":"soft_damage",
			"att":"	curse",
			"buff1":"soft_damage",
			"buff1_c": 1,
			"name":"冷雪心经·阴陵扣命",
			"time":  duration2,
			"buff_msg": msg,
			"disa_msg": HIG"$N浑身一震，精神抖擞了许多。\n"NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);	
	}
	
	target->set_temp("busy_timer/snowforce",time());
	me->perform_busy(1);
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
