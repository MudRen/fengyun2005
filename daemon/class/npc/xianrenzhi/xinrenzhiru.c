// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［仙人指路］只能对战斗中的对手使用。\n");
	extra=me->query_skill("xianrenzhi",1);
	if(extra<50)
		return notify_fail("你仙人指的修为还不够高。\n");	
	if(target->query_temp("till_death/lockup"))
		return notify_fail(target->name()+"已经受制了！\n");	
	if(me->query("force")<200)
		return notify_fail("你的内力不够\n");
	
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed")/50 + 1;
//	if(me->query("class")!="lama") lvl=lvl/2+1;
	msg = HIR "$N使出［仙人指路］，指风如刀，招招扣向$n的关节要害！" NOR;
	if( random(myexp * lvl)+myexp/2 > yourexp )
	{
		message_vision(msg + "\n", me, target);
		msg = BLU"$n大惊失色，连连中指，一口真气竟提不上来！\n"NOR;
		message_vision(msg, me, target);
		target->set_temp("till_death/lockup",1);
	      	target->start_call_out( (: call_other, __FILE__, "remove_effect",target:), 8+lvl*2);
		me->add("force",-200);
	}
	else
	{
		me->add_temp("apply/attack",extra/3);	
	        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra/3);	
	}
	me->start_busy(2);
	return 1;
}


void remove_effect(object target)
{
   	target->delete_temp("till_death/lockup");
        message_vision("$N身形晃动，从$n的指风中脱离出来。\n");
}
 