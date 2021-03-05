// Silencer@fengyun workgroup	June.2005
// 『摘心式』（zhaixin）：心神类的唯我独尊（需50级摘心手），1000-5500 enhance 300, 30m CDT

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, damage, mod, duration, damage2;
    	string msg;
    	
    	if (me->query("class") != "huashan") 
    		return notify_fail("只有华山弟子可以使用「摘心式」。\n");
    	
    	extra=me->query_skill("zhaixin-claw",1);
    	if (extra<100) return notify_fail("「摘心式」需要100级的「摘心手」\n");

			duration = me->query("timer/pfm/hs_zhaixin")-time()+1800
						-F_ABILITY->check_ability(me,"zhaixin_add")*60;
        if (duration>0)
        	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用摘心式。\n");
    
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("「摘心式」只能对战斗中的对手使用。\n");
        	
    	msg = HIW "$n面色变得惨白如纸，双手提起，指尖发出莹莹的光芒。 
$n忽然用一种奇幻的身法闪到$N面前，双爪电击般抓向$N心口！ \n"NOR;
    
			me->set("timer/pfm/hs_zhaixin",time());    	

			mod = COMBAT_D->can_busy(me, target, "zhaixin-claw");	
			if (!mod) mod = 10000;
    	
    	// 500 + 28*100/5 = 1060
    	// 500 + 139 * 180/5 = 5504;
    	    	
//		extra = extra > 180? 180: extra;	// capped.
	
			damage = 500 + F_LEVEL->get_level(me->query("combat_exp")) * extra/5;			
	
		if (userp(me) && userp(target))
				damage = damage/2;
		
		damage2= damage * F_ABILITY->check_ability(me,"3_zhaixin_add",3)/10;
			
		damage  = COMBAT_D->magic_modifier(me, target, "sen", damage);
		damage2 = COMBAT_D->magic_modifier(me, target, "kee", damage2);
  
    	
    if (COMBAT_D->do_busy_attack(me, target, "zhaixin-claw/zhaixin","unarmed", 120 + extra, mod)){   
	        target->receive_wound("sen", damage ,me);
	        if (damage2)	target->receive_damage("kee",damage2,me);
	        	
	        if (target->query("eff_sen")< 0 || target->query("eff_kee")<0)
	        	msg += RED"\n$N"RED"用不可置信的眼光看着自己心口的血洞，身子一晃，倒在地上。 \n" NOR;
	        else
	        {
	        	msg += YEL"\n$N勉力避开了心口要害，爪风过处，却也是眼前一黑，鲜血狂喷。\n"NOR;
	        	message_vision(msg, target, me);
    			COMBAT_D->report_status(target);
    			COMBAT_D->win_lose_check(me,target,damage);
    			me->perform_busy(3);
    			return 1;	
    		}
	        		
    	}
    	else 
    		msg += HIC"\n$N连忙收招封住$n手腕，在森森爪影下旋身急退，躲开了$n的致命一击。 \n" NOR;

    	message_vision(msg, target, me);
    	me->perform_busy(5);
    	return 1;
}
