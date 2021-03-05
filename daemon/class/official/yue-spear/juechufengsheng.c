#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string forceskill,msg;
		int extra, exp_bonus, stage, kee;
		int tmp;
		object weapon;
	
		if (me->query("family/master_id") != "master yue" || me->query("class")!="official")
			return notify_fail("『绝处逢生』是岳飞弟子的绝招。\n");
	
		weapon=me->query_temp("weapon");
 		extra = me->query_skill("yue-spear",1);
		tmp = me->query_skill("manjianghong",1);
    	    	
    	if (extra < 160 ||tmp < 150 )
    		return notify_fail("『绝处逢生』需要160级的岳家中平枪法和150级的满江红心法。\n");
    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("『绝处逢生』只能对战斗中的对手使用。\n");
	    
	    
	    // SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/yue-spear_juechufengsheng");
	    
	    switch (stage) {
	    	case 0:
	    	case 1:	kee = 60;  break;	
	    	case 2:	kee = 70;  break;		// L90
	       	case 3:	kee = 80; break;			// L100
	     }
	      
	      kee += F_ABILITY->check_ability(me,"3_jcfs_add",3);
	        
        if (me->query("kee") > me->query("max_kee") *kee/100)
        	return notify_fail("『绝处逢生』只能在自身气血值降至"+kee+"％以下时才能使用。\n");
        
        // atk 180, dmg 480
        
   		me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", tmp*3);
        msg = HIW  "\n$N"HIW"大喝一声，双手抓住枪柄，斗然间拧腰纵臂，回身出枪，直刺$n"HIW"面门！！\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
   		me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -tmp*3);
        me->perform_busy(2); 
        return 1;
}
