
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl;
    	mapping buff;
      	
    	if( !target ) target = me;
    		else if( me != target)
        		return notify_fail("『击星诀』只可以用在自己的身上。\n");
    
    	if((int)me->query_skill("qixing",1) < 80 )
        	return notify_fail("『击星诀』需要80级七星法！\n");
 	    
    	if(ANNIE_D->check_buff(target, "damageup")
    		|| ANNIE_D->check_buff(target,"powerup2"))
		return notify_fail("你已经在施展类似的心诀了。\n");
    
    	if((int)me->query("mana") < 150 )
        	return notify_fail("『击星诀』需要150点法力！\n");
    	if(userp(me))	me->add("mana", -150);  
    	
    	msg = HIC "\n$N口中念念有词，一道光芒从$N头顶射出，缭绕在$N周围！\n" ;
	msg +="光芒化成一股力量，注入了$N的全身！\n\n"NOR;

	// 200 + 50  = 250 /5 = 50
	lvl = me->query_skill("spells")/5;
                
        buff =
		([
			"caster":me,
			"who": me,
			"type":"damageup",
			"att": "bless",
			"name":"七星法·击星诀",
			"buff1":"apply/damage",
			"buff1_c":lvl,
			"time":   300,
			"buff_msg":msg,
		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
    	return 1;
}

