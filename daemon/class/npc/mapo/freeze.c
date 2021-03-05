// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int ap, dp,myexp;
    	mapping buff;
    	
    	if(!me->is_fighting())
		return notify_fail("麻婆寒练术只可以在战斗中施展！\n");
    	
    	if((int)me->query_skill("mapo", 1) < 100 )
        	return notify_fail("你的麻婆寒练术不够高！\n");
    
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||target->is_corpse()
		||target==me)
        	return notify_fail("你要对谁施展这个法术？\n");

    	if (ANNIE_D->check_buff( target,"freeze"))
    		return notify_fail("你现在并不需要施展麻婆寒练术。\n");

    	if((int)me->query("mana") < 100 )
        	return notify_fail("你的法力不够！\n");

    	if((int)me->query("sen") < 50 )
        	return notify_fail("你的精神没有办法有效集中！\n");

    	if (userp(me)) 	me->add("mana", -100);
    	if (userp(me))	me->receive_damage("sen", 50);
    
    	msg = HIW "\n$N双手一聚，形成一团奇冷的寒气，向$n射来！\n\n"NOR ;
    	message_vision(msg, me, target);
    
    	ap = me->query_skill("mapo",1);
    	myexp = me->query("combat_exp");
    	ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
    	dp = target->query("combat_exp");
    
    	if (random(ap + dp) > dp )
    	{
		buff =
		([
			"caster":me,
			"who": target,
			"type":"freeze",
			"att":"curse",
			"name":"麻婆寒练术·冰封",
			"buff1": "disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type": HIW "<冻僵中>" NOR,
			"time":  10,
			"buff_msg": YEL"$N躲避不及，身子一颤，便如是给人封了穴道一般。\n"NOR,
			"disa_msg": HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);
				
		/*
		msg +="奇冷的寒气包围了$n的全身，将$n凝聚成冰块！\n";
        	target->set_temp("disable_inputs",1);
        	target->set("disable_type",HIW "<冻僵中>" NOR);
        	target->set_temp("is_unconcious",1);
        	target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),10);*/
    	} else  {
    		msg = "但是被$n躲开了。\n";
        	message_vision(msg+NOR, me, target);
    	}
    	me->perform_busy(2);
    	return 1;
}

/*
void remove_frozen(object me)
{
    	me->delete("disable_type");
    	me->delete_temp("disable_inputs");
    	me->delete_temp("is_unconcious");
    	if(!me->is_ghost())
		message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR, me);
}

*/
