//	HARM TOUCH
// 			--- Revised by Silencer@fy4 

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int skill_bonus, myexp, cpexp, damage, duration, mod,stage;
    	
    	if(me->query("class")!="shenshui")
    		return notify_fail("只有神水宫弟子才能使出『唯我独尊』的绝技。\n");

    	if (me->query_skill("nine-moon-claw",1) < 100)
    		return notify_fail("『唯我独尊』需要100级的九阴白骨爪。\n");
    	
    	if ( me->query_skill_mapped("force") != "nine-moon-force")
    		return notify_fail("『唯我独尊』需要九阴心经的辅助。\n");
    	
 		duration = me->query("timer/ss_suicidal")-time()+ 1800 - F_ABILITY->check_ability(me,"wwdz_add")*60;
        if (duration>0)
        	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『唯我独尊』\n");
 	 	 		
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("『唯我独尊』只能对战斗中的对手使用。\n");
 		
    	msg = HIR "$N"HIR"双目尽赤，狂喷鲜血，祭出九阴白骨爪最后一式『唯我独尊』，瞬时间天地为之变色！！\n\n"NOR;
    
    	skill_bonus = me->query_skill("nine-moon-force",1) + me->query_skill("nine-moon-claw" ,1);                  
    	    	
    	// 180 + 200 = 360/40 = 9
    	
    	mod = COMBAT_D->can_busy(me, target, "nine-moon-claw");	
		if (!mod) mod = 10000;
    	    	
    	skill_bonus = 5 + ((skill_bonus>=0) ? skill_bonus/40 : 1) ;
    
       	// SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/nine-moon-claw_weiwoduzun");
	    
	    switch (stage) {
	    	case 0:
	    	case 1:	damage = 3000; break;		// almost half kee
	    	case 2:	damage = 4500; break;		// L90
	       	case 3:	damage = 6000; break;		// L100
	     }	
       	
       	damage = damage * (100 + F_ABILITY->check_ability(me,"wwdz2_add")*5)/100;
       	
       	damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
    	
    	if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw/weiwoduzun","unarmed", skill_bonus*100, mod))
    	{
    	
        	msg += WHT"结果$p"NOR+WHT"被$N"NOR+WHT"攻了个措手不及！\n" NOR;
        	target->receive_damage("kee", damage, me);
        	target->receive_wound("kee", damage, me);
        	message_vision(msg, me, target);
        	COMBAT_D->report_status(target,0);
    	}
    	else {
    		msg += YEL"可是$p"NOR+YEL"还是躲过了$N"NOR+YEL"的最后一击！！\n"NOR;
			message_vision(msg, me, target);
		}
    	
		me -> set("timer/ss_suicidal", time());
		me ->perform_busy(2);
		return 1;
}


