// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int cast(object me, object target)
{
		int i,t,skill,level,sec,duration,duration2;
		mapping buff;

		if (me->query("class") != "moon")
        	return notify_fail("只有皓月宫中人才能施展『无方变幻』。\n");

        skill = me->query_skill("heart-listening",1);
		if (skill < 120 && userp(me))
        	return notify_fail("『无方变幻』需要至少120级的幻念聆音。\n");

		duration = me->query("timer/no_busy") + 300 - time();
		if (duration > 0 && userp(me))
        	return notify_fail("你还需等待"+ duration+"秒钟左右才能再次施出『无方变幻』\n");

		if( ANNIE_D->check_buff(me,"feat")) 
			return notify_fail("『无方变幻』与你现在使用的某一特技不能同时使用。\n");

        if(me->query("mana") < 100 && userp(me))    
        	return notify_fail("你的法力不够。\n");
        if (userp(me))
	        me->add("mana", -100);
	
		me->set("timer/no_busy",time());
		
		duration2 = 90 + F_ABILITY->check_ability(me,"wfbh_add")*6 ;
		
		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"att":"bless",
				"name":"幻念聆音·无方变幻",
				"buffup_name":"no_busy",
				"buffup_type":CYN"$N"NOR+CYN"身畔寒气流转，飘忽灵动，变幻无方。\n"NOR,
				"buffup_ratio":0,
				"time":duration2,
				"buff_msg":HIW"$N"HIW"默运玄功，身边为一层若即若离，似真似幻的轻烟薄雾淡淡笼上。\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}


