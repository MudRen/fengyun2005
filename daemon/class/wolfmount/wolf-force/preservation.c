// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;
int stone_done(object me, object caster);

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;
    	object *inv, *wolf;

		if (me->query_skill("wolf-force",1) < 150 || me->query_skill("summonwolf",1)< 150)
        	return notify_fail("『潜狼诀』需要150级的天狼心法和150级唤狼之术。\n");
                     
    	// duration = 10 mins.
		duration = me->query("timer/pfm/wm_preservation")+ 90 -time();
		if (duration>0)
    		return notify_fail("『潜狼诀』需要"+duration+"秒钟后才能再次运用。\n");

    	if( me->query("force") < 100 )
        	return notify_fail("『潜狼诀』需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

    	msg = HIB"$N暗念心诀，身影渐渐地变虚变淡。\n"NOR;
    	
		buff =
			([
				"caster":me,
				"who":me,
				"type":"wm-detaunt",
				"att":"bless",
				"name":"天狼心法·潜狼",
				"buff1": "pfm/wm_preservation",
				"buff1_c": 3,
				"time":30,
				"buff_msg": msg,
				"finish_function": (: stone_done :),
		]);
		
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/wm_preservation", time());
		return 1;
}

int stone_done(object me, object caster){
	me->delete_temp("pfm/wm_preservation");
	return 1;
}
