// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    int skill;
 	mapping buff;
 	string msg;
 	       
 	skill = me->query_skill("ghosty-force",1);
    
    if ( skill<100)
       	return notify_fail("聚阴诀需要100级的无坎真阴。\n");
        
    if (!target) target = me;
    if( target != me ) 
       	return	notify_fail("你只能用无坎真阴提升自己的防御力。\n");
     
    if( (int)me->query("force") < 150 )     
       	return	notify_fail("需要耗费100点内力。\n");
    me->add("force", -100);
               
    if (ANNIE_D->check_buff(me,"powerup")
    	|| ANNIE_D->check_buff(me,"dodgeup"))
       	return notify_fail("你已经在运用类似的武功了。\n");

    skill = 20 + skill /4;		// 20+200/4 = 70
    	    	
    msg = BGRN + HIW"$N默运无坎真阴神功，全身象一团棉絮般轻飘起来！\n" NOR;

    buff =
		([
			"caster":me,
			"who": me,
			"type":"dodgeup",
			"att":"bless",
			"name":"无坎真阴·聚阴诀",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time": 300,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
   	if (userp(me))	me->perform_busy(1);
   	return 1;
}