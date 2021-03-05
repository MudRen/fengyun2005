
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int skill, add, duration;
		mapping buff;
	
		if(me->query("class")!="beggar")
	    	return notify_fail("只有丐帮弟子才会『斗寒诀』。\n");
		
		skill = me->query_skill("huntunforce", 1);
		if(skill < 150) return notify_fail("『斗寒诀』需要150级的混沌功！\n");

        if( target != me ) 
        	return	notify_fail("『斗寒诀』只能用于自身。\n");
		
        duration = me->query("timer/pfm/gb_douhan")-time() + 300;
    	if (duration>0)
    		return notify_fail("你还需要等待"+(duration/60)+"分钟左右才能再次使用『斗寒诀』\n");
    	       
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
			"time":  180,
			"buff_msg":BGRN+HIW"$N深深地吸了几口气，运混元内力护住全身。\n"NOR,			
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/gb_douhan",time());
		
        return 1;
}

