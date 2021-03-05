// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
    	string msg,msg1;
    	int skill,duration;
    	mapping buff;
    	   	
    	if(me->query("class")!="yinshi")
			return notify_fail("只有帝王谷弟子才能下衰降。\n");
    	
    	skill = me->query_skill("celecurse",1);
    	if(skill<90 && userp(me))
    		return notify_fail("衰降需要90级通天降！\n");

        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种法术只能对战斗中的对手使用。\n");
    	
    	if (ANNIE_D->check_buff(target,"strdown"))
			return notify_fail("对方已经中了衰降了，还不抓紧时机攻击？\n");
		
    	if((int)me->query("sen") < 50 && userp(me))
        	return notify_fail("衰降需要耗费50点的心神！\n");
    	if (userp(me))	me->add("sen",-50);
    		
    	msg = BLU "$N"+BLU"微微俯身，右手按地，念动咒语，空气中洋溢着淡淡的奇异的腥味，腥气最浓烈的地方，
居然慢慢浮现出一个黑色的人影，人影死死地盯着$n，尖声厉叫着向$n扑去！\n\n" NOR;
        	
    	message_vision(msg, me, target);
    	
    	if (target->query("boss")|| target->query("big_boss"))
    		duration = 10;
    	else
    		duration = 30;
    	
    	if( COMBAT_D->do_busy_attack( me, target, "celecurse/weakcurse", "unarmed", 250, 10)) {	
	    	message_vision(YEL"$N被吓得手足无措，黑影化作一道黑光，注入了$N的眉心。\n"NOR, target);
	    	buff = 
			([
				"caster": me,
				"who":   target,
				"type":  "strdown",
				"att":	"curse",
				"name":	"通天降·衰降",
				"buff1":"apply/strength",
				"buff1_c": -5,
				"time":   duration,
				"buff_msg": "",
			]);
			ANNIE_D->buffup(buff);
		
			if (!ANNIE_D->check_buff(me,"strup")) {
				buff = 
				([
					"caster": me,
					"who":    me,
					"type":  "strup",
					"att":	 "bless",
					"name":	 "通天降·衰降",
					"buff1": "apply/strength",
					"buff1_c": 5,
					"time":   duration,
					"buff_msg": "",
				]);
				ANNIE_D->buffup(buff);
			}
		
		} else
			message_vision(WHT"$N冲天而起，躲过了黑光。\n"NOR, target);
	
		me->perform_busy(1);
    	return 1;
}

