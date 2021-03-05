// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill;
        mapping buff;
        
        skill = me->query_skill("notracesnow", 1);
		
		if ((string)me->query("class") != "taoist") {
	  		skill=skill/2;
			if(skill < 30) 
				return notify_fail("需要60级踏雪无痕才能使用『漫天飞雪』\n");
		} else if (skill<30)
			return notify_fail("需要30级踏雪无痕才能使用『漫天飞雪』\n");
        
        if (!target) target = me;
        if( target != me ) 
        	return 	notify_fail("你只能将『漫天飞雪』用在自己的身上。\n");
        
        if (ANNIE_D->check_buff(me,"dodgeup"))
        	return notify_fail("你已经在使用类似的武功了。\n");
        
		buff =
			([
				"caster":me,
				"who": me,
				"type":"dodgeup",
				"att":"bless",
				"name":"踏雪无痕·漫天飞雪",
				"buff1":"apply/dodge",
				"buff1_c":skill,
				"time":  900,
				"buff_msg":BGRN + HIW"$N行功运气，身形居然缓缓上升，如风中的雪花飘逸无定！\n" NOR,
	//			"warn_msg":WHT"『漫天飞雪』的功效快要结束了。\n"NOR,
	//			"disa_msg":YEL"你施展完毕『漫天飞雪』，稳住身形。\n"NOR,
				"special_func":0,
			]);
		ANNIE_D->buffup(buff);
        
        return 1;
}