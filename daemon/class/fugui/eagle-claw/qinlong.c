// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod;
	mapping buff;
	
	if (me->query("class")!="fugui") 
		return notify_fail("『十指擒龙』为富贵特技。\n");
		
	extra=me->query_skill("eagle-claw",1);
	if(extra<50)
		return notify_fail("『十指擒龙』需要50级鹰爪功。\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『十指擒龙』只能对战斗中的对手使用。\n");
	
	if (ANNIE_D->check_buff(target,"pseudo-busy"))
		return notify_fail(target->name()+"已经身法迟钝了。\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");	
	
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
	
	lvl = 200;					
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIW"
$N大喝一声，纵身而上，双手犹如狂风骤雨，来势迅捷刚猛，宛若布下
天罗地网，招招扣向$n的关节要害，正是鹰爪功中的一招『十指擒龙』！\n" NOR;
	message_vision(msg, me, target);
	
	if (COMBAT_D->do_busy_attack( me, target, "eagle-claw/shizhiqinlong","step", lvl, mod))
	{
		msg = BLU"$n大惊失色，竟被$N在脉门上一划，顿时半身麻木！\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "pseudo-busy",
			"att":  "curse",
			"name": "鹰爪功·擒龙",
			"time":  6,
			"buff1": "pseudo-busy",
			"buff1_c": 1,
			"buff_msg": "",
			"condition_type":  "<身法迟钝>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
	} else	{
			msg = YEL"$n不退反进，长袖一圈一带，$N竟递不进招去。\n"NOR;
			message_vision(msg,me,target);
	}
			
	target->set_temp("busy_timer/eagle-claw",time());
	me->perform_busy(1); 
	return 1;
}

