// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
	int extra, timer, duration,tmp, cost;
	object weapon;
	
	if (me->query("class") != "shaolin")
		return notify_fail("『七星夺魄』是少林弟子的绝招。\n");
	
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("duanhun-spear",1);
    	    	
    if (extra < 170 )
    	return notify_fail("『七星夺魄』需要170级的断魂枪法!\n");
    
    timer = 60 - F_ABILITY->check_ability(me,"qixing_add")*2;	
    duration = me->query("timer/pfm/sl_qxdp")+timer-time();
	if (duration>0)
    		return notify_fail("『七星夺魄』需要"+chinese_number(duration)+"秒后才能再次使用。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("『七星夺魄』只能对战斗中的对手使用。\n");	      
 	
		msg = HIW" \n$N"HIW"长啸一声，凌空而起，手中"+weapon->name()+HIW"化作一道银虹，向$n飞掷而出，
闪电一样的白光，寒星一样的冷芒，一枪七星，同时飞击！七星夺魄，一枪绝命！\n"NOR;
		
		message_vision(msg, me, target);
		me->add_temp("apply/attack", extra*3);
		me->add_temp("apply/damage", extra*6);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -extra*6);
        
        if (target)
        if (target->query_temp("damaged_during_attack"))
        	target->add_hate(me,extra*8);
        
        me->set("timer/pfm/sl_qxdp",time());
        
        me->perform_busy(1); 
        return 1;
}

