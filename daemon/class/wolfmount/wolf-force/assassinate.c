// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;

		if (me->query_skill("wolf-force",1) < 170 || me->query_skill("summonwolf",1)< 270)
        	return notify_fail("『神狼诀』需要170级的天狼心法和270级的唤狼术。\n");
        		
    	if( target != me )
        	return notify_fail("『神狼诀』只能用于自身。\n");
    	    	
    	// duration = 20mins.
		duration = me->query("timer/pfm/wm_assassinate")+ 1200 -time();
		if (duration>0)
    	return notify_fail("『神狼诀』极耗元神，需要"+chinese_number(duration/60)+"分钟后才能再次运用。\n");
    	
    	if (ANNIE_D->check_buff(me,"assassinate"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	if( me->query("force") < 100 )
        	return notify_fail("『神狼诀』需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

    	msg = BRED + HIW"\n$N藏眼神，凝耳韵、调鼻息、缄舌气，如黑夜独行的狼，一触待发！\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"assassinate",
			"att":"bless",
			"name":"天狼心法·神狼诀",
			"buff1":"pfm/wm_assassinate",
			"buff1_c":skill,
			"time": 16,
			"buff_msg": msg,
		]);
		me->set("timer/pfm/wm_assassinate", time());
		
		ANNIE_D->buffup(buff);
	   	return 1;
}
