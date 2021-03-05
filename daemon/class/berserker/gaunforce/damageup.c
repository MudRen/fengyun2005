#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
    
    	if (ANNIE_D->check_buff(me,"damagecurse"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	skill = me->query_skill("gaunforce",1);
    	if( (int)me->query("force") < 100 )
        	return notify_fail("『碎玉撼天破诀』需要100点的内力。\n");
    	if (userp(me))
		{
    		me->add("force", -100);
    	}

    	msg = YEL "$N"NOR+YEL"沉气收心，缓缓地吐出一口长气，脸色变得如枯木般毫无表情。\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"damagecurse",
			"att":"bless",
			"name":"碎玉神罡·碎玉撼天破诀",
			"time": 60,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
