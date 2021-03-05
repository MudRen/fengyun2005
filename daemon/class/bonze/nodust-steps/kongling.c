// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, num;
        
        if(me->query("class")!="bonze") 
		return notify_fail("只有兴国高僧才能使用『空灵』\n");
	
		skill = me->query_skill("nodust-steps", 1);		
		if(skill < 100) 	
			return notify_fail("『空灵』需要100级的无尘步法！\n");
	   
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("『空灵』只能用在自己身上。\n");
        	      
        if( me->query("force") < 100 )     
        	return  notify_fail("『空灵』需要100点内力。\n");   	
		me->add("force", -100);
	
       	me->set("bellicosity",0);
        	
        message_vision( BGRN + WHT "$N低颂佛号，前后各行三步，步伐凝重，运气调息间将杀气收敛殆尽。\n" NOR, me);
        me->perform_busy(1);
        return 1;
}