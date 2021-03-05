#include <ansi.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
       object weapon;
        int extra;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("明月几时有只能对战斗中的对手使用。\n");
		extra = me->query_skill("moon-blade",1);
        if((int) extra <= 120)
                return notify_fail("你的圆月魔刀还不够精纯，不能出明月几时有。\n");
	
		if (target->query_condition("moon-blade"))
			return notify_fail("对手已经中招了。\n");
			
        message_vision(RED"$N大喝一声，身形在$n面前一闪。\n虽然谁也没有看清楚怎么回事，但谁都
可以感觉到，$N已然出刀！\n"NOR,me,target);
		weapon=me->query_temp("weapon");

		if (weapon->query("for_modao"))
		if(random((extra*extra*extra*extra)/50 + target->query("combat_exp"))
			>(target->query("combat_exp")))
		{
			me->set_temp("kill_other",1);
			weapon=me->query_temp("weapon");
		    target->remove_all_killer();
			target->set_temp("last_damage_from",me);
			target->apply_condition("moon-blade",1);
		}
		else
		{
			message_vision(HIW"但$n就地一滚，总算躲过了$N这凌厉的一招！\n\n"NOR,me,target);
			me->start_busy(3);
		}

	else
	{	
		me->add_temp("apply/damage",extra);
		me->add_temp("apply/dodge",extra/2);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
		me->add_temp("apply/damage",-extra);
		me->add_temp("apply/dodge",-extra/2);
		me->start_busy(3);
	}
        return 1;
}

/*
void kill_him(object me, object target)
{
        string msg;

		
  	msg =  "\n"HIC+target->name()+"忽然由顶至踵，分为两片，向两边倒了下去。\n" NOR;

//        message_vision(msg, me,target);
		message("vision",msg,environment(target));
		target->set_temp("last_damage_from",me);
        target->die();

		me->set_temp("kill_other",0);

        return ;
}
*/