// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;

		if (me->query_skill("wolf-force",1) < 160)
        	return notify_fail("『战狼诀』需要160级的天狼心法。\n");
        		
    	if( target != me )
        	return notify_fail("『战狼诀』只能用于自身。\n");
    	    	
    	// duration = 10 mins.
		duration = me->query("timer/pfm/wm_bloodthirsty")+ 600 -time();
		if (duration>0)
    	return notify_fail("『战狼诀』极耗元神，需要"+chinese_number(duration/60)+"分钟后才能再次运用。\n");
    	
    	if (ANNIE_D->check_buff(me,"bloodthirsty"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	if( me->query("force") < 100 )
        	return notify_fail("『战狼诀』需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

    	msg = BRED+HIW"$N突然长啸一声，变掌为抓，满头长发，齐地飘起！\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"bloodthirsty",
			"att":"bless",
			"name":"天狼心法·战狼诀",
			"buff1":"pfm/wm_bloodthirsty",
			"buff1_c":1,
			"time": 90,
			"buff_msg": msg,
		]);
		
		me->set("timer/pfm/wm_bloodthirsty", time());
		
		ANNIE_D->buffup(buff);
	
    	return 1;
}
