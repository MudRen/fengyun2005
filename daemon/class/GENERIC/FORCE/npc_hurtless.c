//		This perform is to prevent BOSS etc drop to very low atk/def due to hurt

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int skill, add, duration;
		mapping buff;
	
		if (userp(me))
			return notify_fail("你使用的技能里没有这个特技。\n");
		
        target = me;
        
        if (ANNIE_D->check_buff(me, "hurtless"))
        	return notify_fail("你已经在使用类似的特技了。\n");  
        
        buff =
		([
			"caster":me,
			"who": me,
			"type":"hurtless",
			"att":"bless",
			"name":"混沌功·斗寒诀",
			"buff1":"hurtless",
			"buff1_c":1,
			"time":  1800,
			"buff_msg":BGRN+HIW"$N深深地吸了几口气，眼中精光湛现。\n"NOR,			
		]);
		ANNIE_D->buffup(buff);
		
        return 1;
}

