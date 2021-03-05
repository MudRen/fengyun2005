#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int n,mod;
    	int my_weapon, y_weapon;
    	
    	if (me->query("class")!="wudang")
    		return notify_fail("『千里流沙』是武当的独有武功。\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        	return notify_fail("『千里流沙』只能对战斗中的对手使用。\n");

    	my_weapon = me->query_temp("weapon");
    	y_weapon = target->query_temp("weapon");
    	
    	mod = COMBAT_D->can_busy(me, target, "taiji-sword");	
	if (!mod)
		return notify_fail(HIW"此人身势灵活，功力深湛，不会被此剑法迷惑的。\n"NOR);
    	
    	if( target->is_busy() )
        	return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        
		msg=YEL"$N"YEL"使出太极剑法中的流沙诀攻向$n"YEL"，剑势有如千里流沙般连绵不绝，暗含杀机！...\n"NOR;
    	
    	me->perform_busy(1);
       	 
    	if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/nianzijue", "weapon", 400, mod))
    	{
			msg += WHT"结果$p"WHT"被$P"WHT"攻了个措手不及，动作迟滞，如陷沙积！\n\n" NOR;
			message_vision(msg, me, target);
			n= random(me->query_skill("taiji-sword", 1) / 40) + 2;
			target->force_busy(1);
    		target->set_temp("busy_timer/taiji-sword",time());
			target->set_temp("annie/wd_busy_test_1",time());

    	} else {
        	msg += CYN"可是$n"CYN"看破了$N"CYN"的企图，避实以待，破去$N"CYN"这式虚招。\n\n" NOR;
        	message_vision(msg, me, target);
    	}

    	return 1;
}

