#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int your_exp,n,mod, enhance;
    	int my_weapon, y_weapon;
    	
		if (userp(me))
			return notify_fail("你不是武当弟子亚。\n");
		
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("『粘字诀』只能对战斗中的对手使用。\n");

    	my_weapon = me->query_temp("weapon");
    	y_weapon = target->query_temp("weapon");
    	
    	if( target->is_busy() )
        	return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
    	
    	mod = COMBAT_D->can_busy(me, target, "three-sword");	
		if (!mod)
		return notify_fail(HIW"此人身势灵活，功力深湛，不会被此剑法迷惑的。\n"NOR);
    	       	
    	if (y_weapon) {
    		msg = CYN"\n$N"+CYN"使出三才剑法中的粘字诀，手中的"+my_weapon->name()+CYN"东一指，西一划，看似毫无章法，
但每发一招，便似放出一条细丝，缠向"+"$n"+CYN"的"+y_weapon->name()+CYN"。\n";
	} 	else {
    		msg = CYN"\n$N"+CYN"使出三才剑法中的粘字诀，手中的"+my_weapon->name()+CYN"东一指，西一划，看似毫无章法，
但每发一招，便似放出一条细丝，缠向"+"$n"+CYN"的手臂。\n";
	}
    	
    	me->perform_busy(1);
    	enhance= 600;
		if (COMBAT_D->do_busy_attack( me, target, "three-sword/nianzijue", "step", enhance, mod))
		{
        	msg += "结果$p"CYN"被$P"CYN"攻了个措手不及！\n\n" NOR;
			message_vision(msg, me, target);
			n= random(me->query_skill("three-sword", 1) / 40) + 2;
			if (n>3) n=3;
			target->force_busy(n);
    		target->set_temp("busy_timer/three-sword",time());
    	} else {
        	msg += "可是$p"CYN"看破了$P"CYN"的企图，并没有上当。\n\n" NOR;
        	message_vision(msg, me, target);
    	}
    	return 1;
}

