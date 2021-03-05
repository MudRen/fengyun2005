// Silencer@fengyun

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, cps_skill;
        mapping buff;
        
        if(me->query("class")!="knight") 
		return notify_fail("只有快活林弟子才能使用行云步。\n");
	
		skill = me->query_skill("windy-steps", 1);		
		if(skill < 150) 	
			return notify_fail("行云步需要150级的急风三十六式！\n");
	     
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("行云步只能用在自己身上。\n");
        	      
        if (ANNIE_D->check_buff(me,"khl-atk-stance")>0)
        	return notify_fail("你已经在使用行云步了。\n");
        
        if (me->query_temp("timer/khl-stance")+30>time())
	    	return notify_fail("快活林的步法每30秒钟最多转换一次。\n");

        if (ANNIE_D->check_buff(me,"khl-df-stance")>0)
        	ANNIE_D->debuff(me,"khl-df-stance");
        
        if (ANNIE_D->check_buff(me,"dodgeup")>0 || ANNIE_D->check_buff(me,"powerup")>0)
        	return notify_fail("你已经在使用类似的武功了。\n");
        
	    me->set_temp("timer/khl-stance",time());
	    
                
        buff =
			([
				"caster":me,
				"who": me,
				"type": "khl-atk-stance",
				"type2":"powerup",
				"att":"bless",
				"name":"急风三十六式·行云步",
				"buff1": "apply/attack",
				"buff1_c":100,
				"buff2": "apply/parry",
				"buff2_c":-200,	
				"buff3": "apply/dodge",
				"buff3_c":-200,	
				"time":  600,
				"buff_msg":BGRN + HIY"$N身形一晃滑出丈余，立时又回到了原地，如行云流水，一气呵成。\n"NOR,
			]);
		ANNIE_D->buffup(buff);

        return 1;
}