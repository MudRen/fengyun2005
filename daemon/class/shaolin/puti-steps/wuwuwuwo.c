// fyteam
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill;
    	mapping buff;
    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("唯有少林高僧才能使用『无物无我』\n");
    	   	
    	if (!target) target = me;
    	if( target != me ) 
    		return notify_fail("你只能将『无物无我』用在自己的身上。\n");
    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 50) 
			return notify_fail("『无物无我』至少需要50级菩提虚空步法！\n");
	 
    	if (ANNIE_D->check_buff(me,"dodgeup"))
     		return notify_fail("你已经在使用类似的武功了。\n");
     		
    	if( (int)me->query("force") < 100 )     
    		return notify_fail("『无物无我』需要耗费100点内力。\n");
    	if (userp(me))	me->add("force", -100);
	      		
     	if (me->query("class")!="shaolin" && me->query("class")!="official")  
     		skill=skill/2;
     	    	
     	buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"dodgeup",
			"att":	"bless",
			"name":	"菩提虚空步法·无物无我",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time":  900 ,
			"buff_msg":BGRN + HIG"$N摒除心中所有杂念，灵台一片明净，霎时间身轻似无物。\n"NOR,			
		]);
		ANNIE_D->buffup(buff);
        
        if (me->is_fighting())
        	me->perform_busy(2);
        
        return 1;
        
}


