// silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int hit_break(object target, object me, int factor);

int perform(object me, object target)
{
	string msg;
	int extra, my_exp, exp_factor;

	    if(userp(me))
                return notify_fail("你所选用的武功中没有这种必杀技。。\n");  

	my_exp = (int) me->query("combat_exp");
	exp_factor = 750000000/my_exp;
        if (exp_factor < 100) exp_factor = 100;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破颅］只能对战斗中的对手使用。\n");
	
	extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
		+ me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
	extra = extra *4;
	
	
		target->delete_temp("last_damage_from");
		me->add_temp("apply/attack", extra/6);	
		me->add_temp("apply/damage", extra/10);
		msg = HIW"$N身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n身边，
袖中伸出纤纤素手，五根手指疾抓$n$l。\n"NOR ;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra/6);
		me->add_temp("apply/damage", -extra/10);
                //<- adjust damage here
                
		if (target->query_temp("last_damage_from")==me && (int)me->query("timer/polu") + exp_factor/20 < time()) {
			//<- Adjust timer here
			message_vision(HIW"$N一招得手，更不稍停，反掌间五根手指已向$n的头顶插了下去。\n"NOR,me,target);
		        hit_break(target, me, extra/2);
		}
		if (me->query_busy()<2) 
			me->start_busy(2);    //<- Addjust busy here
		

	return 1;
}

int hit_break(object target, object me, int factor) {
	int resist;
	if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
	{
		message_vision(MAG"$N惨叫一声，顶门已被$n的手掌罩住！\n"NOR,target,me);
		resist=target->query("resistance/kee");
		target->set("resistance/kee",0);
		target->receive_wound("kee",factor/2+random(factor)/2);
		target->receive_damage("kee",factor/2+random(factor)/2);
		target->set("resistance/kee",resist);
		target->set_temp("last_damage_from",me);
		COMBAT_D->report_status(target);
	}
	else	
		message_vision(YEL"$N不慌不忙，抢前半步，避开了脑门要害。\n"NOR,target);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : perform polu
极毒，极狠，命中率极高的一招，为神水武功的
精华所聚。出招如鬼，收招似魅，只是由于杀气
太盛，不能与“假死“同时使用。

HELP
        );
        return 1;
}