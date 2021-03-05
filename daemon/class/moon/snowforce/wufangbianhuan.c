// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int i,t,skill,level,sec,duration;
		mapping buff;

		if (userp(me))
			return notify_fail("你学的武功中没有这个特技。\n");
		
		if (me->query("class") != "moon")
        	return notify_fail("只有皓月宫中人才能施展『无方变幻』。\n");

        skill = me->query_skill("snowforce",1);
		if (skill < 140 && userp(me))
        	return notify_fail("『无方变幻』需要至少140级的冷雪心经。\n");

		duration = me->query("timer/no_busy") + 1800 - time();
		if (duration > 0 && userp(me))
        	return notify_fail("你还需等待"+ duration/60+"分钟左右才能再次施出『无方变幻』\n");

		if( ANNIE_D->check_buff(me,"feat")) 
			return notify_fail("『无方变幻』与你现在使用的某一特技不能同时使用。\n");

        if(me->query("force") < 100 && userp(me))    
        	return notify_fail("你的内力不够。\n");
        if (userp(me))
	        me->add("force", -100);
	
		me->set("timer/no_busy",time());
		
		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"att":"bless",
				"name":"冷雪心经·无方变幻",
				"buffup_name":"no_busy",
				"buffup_type":CYN"$N"NOR+CYN"身畔寒气流转，飘忽灵动，变幻无方。\n"NOR,
				"buffup_ratio":0,
				"time":120,
				"buff_msg":HIW"$N"HIW"默运玄功，身边为一层若即若离，似真似幻的轻烟薄雾淡淡笼上。\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}


