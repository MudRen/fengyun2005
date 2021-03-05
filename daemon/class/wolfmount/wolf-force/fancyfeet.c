// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill, duration;
    	string msg;
    	mapping buff;
    	object *inv, *wolf;

		if (me->query_skill("wolf-force",1) < 170 || me->query_skill("summonwolf",1)< 200)
        	return notify_fail("『舞狼诀』需要170级的天狼心法和200级唤狼之术。\n");
                     
    	// duration = 10 mins.
		duration = me->query("timer/pfm/wm_fancyfeet")+ 90 -time();
		if (duration>0)
    		return notify_fail("『舞狼诀』需要"+duration+"秒钟后才能再次运用。\n");

        inv = all_inventory(environment(me));
        wolf = filter_array(inv,(: $1->query("possessed")==$2 && $1->query("id")=="wolf" :), me);
        if (!wolf || sizeof(wolf)<1)
        	return notify_fail("『舞狼诀』只能用在你自己唤出的狼身上。\n");	
        if (!objectp(wolf[0]))
        	return notify_fail("『舞狼诀』只能用在你自己唤出的狼身上。\n");	
        
    	if( me->query("force") < 100 )
        	return notify_fail("『舞狼诀』需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

    	msg = HIB"$n"HIB"深吸一口气将手掌搭在$N"HIB"背心，刹时间，似乎心意与$n"HIB"相通。。。。
"HIG"$n双眼闪动莹莹的绿光，抖了抖身体，发出一声深沉有力的长嚎！\n"NOR,

		buff =
			([
				"caster":me,
				"who":wolf[0],
				"type":"feat",
				"type2": "evade",
				"att":"bless",
				"name":"天狼心法·舞狼",
				"buffup_name":"evade",
				"buffup_type":""+3,
				"buffup_ratio":3,
				"time":10,
				"buff_msg": msg,
				"special_func":2,
			]);
		
		me->set("timer/pfm/wm_fancyfeet", time());
		ANNIE_D->buffup(buff);
    	return 1;
}
