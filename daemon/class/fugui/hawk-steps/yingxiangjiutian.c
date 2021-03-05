// Silencer@fengyun
// 『鹰翔九天』：提高速度。（需100级鲲鹏步法）

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, agi_skill;
        mapping buff;
        
        if(me->query("class")!="fugui") 
		return notify_fail("只有富贵弟子才能使用『鹰翔九天』\n");
	
		skill = me->query_skill("hawk-steps", 1);		
		if(skill < 100) 	
			return notify_fail("『鹰翔九天』需要100级的鲲鹏步法！\n");
	       
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("『鹰翔九天』只能用在自己身上。\n");
        	
        if (ANNIE_D->check_buff(me,"agiup"))
        	return notify_fail("你已经在使用类似的武功了。\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("『鹰翔九天』需要100点内力。\n");   	
		me->add("force", -100);
	
		agi_skill = skill/20;	// 160/20 = 8
	
		buff =
		([
			"caster":me,
			"who": me,
			"type":"agiup",
			"att":"bless",
			"name":"鲲鹏步法·鹰翔九天",
			"buff1": "apply/agility",
			"buff1_c":agi_skill,
			"time":  900,
			"buff_msg":BGRN + WHT"$N钻天鹞子般腾身而起，半空中似是打了个霹雳，山雨欲来！\n"NOR,
		]);
		ANNIE_D->buffup(buff);
        return 1;
}