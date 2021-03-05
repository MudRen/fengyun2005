// Silencer@fengyun

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, cps_skill;
        mapping buff;
        
        if(me->query("class")!="knight") 
			return notify_fail("只有快活林弟子才能使用流云步。\n");
	
		skill = me->query_skill("windy-steps", 1);		
		if(skill < 100) 	
			return notify_fail("流云步需要100级的急风三十六式！\n");
		     
	    if(!target) target = me;
	    if( target != me ) 
	      	return 	notify_fail("流云步只能用在自己身上。\n");
	        			
	    if (ANNIE_D->check_buff(me,"khl-df-stance")>0) 
			return notify_fail("你已经在使用流云步了。\n");
	    
	    if (me->query_temp("timer/khl-stance")+30>time())
	    	return notify_fail("快活林的步法每30秒钟最多转换一次。\n");
	    	
	    if (ANNIE_D->check_buff(me,"khl-atk-stance")>0) {
	    	ANNIE_D->debuff(me,"khl-atk-stance");
	    }
	    
	    if (ANNIE_D->check_buff(me,"dodgeup")>0 || ANNIE_D->check_buff(me,"powerup")>0)
        	return notify_fail("你已经在使用类似的武功了。\n");
	    
	    me->set_temp("timer/khl-stance",time());	    
	    	    	
		cps_skill = skill/20;
		
		buff =
			([
				"caster":me,
				"who": me,
				"type": "khl-df-stance",
				"type2":"dodgeup",
				"att":"bless",
				"name":"急风三十六式·流云步",
				"buff1": "apply/composure",
				"buff1_c":cps_skill,
				"buff2": "apply/dodge",
				"buff2_c": skill/3,
				"time":  600,
				"buff_msg":BGRN + WHT"$N身形一晃滑出丈余，立时又回到了原地，如行云流水，一气呵成。\n"NOR,
			]);
		ANNIE_D->buffup(buff);	
        return 1;
}

