// Silencer@fengyun
// 『饥鹰搏兔』：riposte。

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, timer, duration, time;
        mapping buff;
        
        if(me->query("class")!="fugui") 
		return notify_fail("只有富贵弟子才能使用『饥鹰搏兔』\n");
	
		skill = me->query_skill("hawk-steps", 1);		
		if(skill < 160) 	
			return notify_fail("『饥鹰搏兔』需要160级的鲲鹏步法！\n");
	        
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("『饥鹰搏兔』只能用在自己身上。\n");
        
        timer = 180;		
		duration = me->query("timer/pfm/hk_jiying")+timer-time();
		if (duration>0)
    		return notify_fail("你真气已散，一时无法再次使用饥鹰搏兔（需"+duration+"秒）。\n");
        
        if (ANNIE_D->check_buff(me,"riposte"))
        	return notify_fail("你已经在使用类似的武功了。\n");
       
		time = 20 + F_ABILITY->check_ability(me,"jybt_add")*2;
		me->set("timer/pfm/hk_jiying", time());
//		write ("time is "+ time + "\n");
		buff =
		([
			"caster":me,
			"who": me,
			"type":"riposte",
			"att":"bless",
			"name":"鲲鹏步法·饥鹰搏兔",
			"buff1": "counter_action_extra",
			"buff1_c":1,
			"time":  time,
			"buff_msg":BGRN + WHT"$N"NOR+BGRN + WHT"身形凌空，手足旋舞，如饥鹰搏兔，猛然全速下搏。！\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	
        return 1;
}
