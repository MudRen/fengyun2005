// Silencer@fy4

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl;
	mapping buff;
		
   	if((int)me->query_skill("qixing",1) < 60 )
   	     return notify_fail("『捍星诀』需要60级七星法！\n");
      	
    	if( !target ) target = me;
    	else if( me != target)
        	return notify_fail("『捍星诀』只可以用在自己的身上。\n");
    
	if( ANNIE_D->check_buff( me, "armorup")
		|| ANNIE_D->check_buff(me,"powerup2"))
        	return notify_fail("你已经在使用类似的心诀了。\n");

    	if(me->query("mana") < 150 )
        	return notify_fail("『捍星诀』需要150点法力！\n");
    	me->add("mana", -150);
    
    	msg = HIC "\n$N口中念念有词，一道光芒从$N头顶射出，缭绕在$N周围！\n" ;
	msg +="光芒化成一身软甲，保护住$N的全身！\n\n"NOR;
	
//	50 + 200 = 250	/5 = 50
	lvl = me->query_skill("spells")/5;
                
        buff =
		([
			"caster":me,
			"who": me,
			"type":"armorup",
			"att":"bless",
			"name":"七星法·捍星诀",
			"buff1":"apply/armor",
			"buff1_c":lvl,
			"time":   360,
			"buff_msg":msg,
		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
    	return 1;
}
