// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int i,t,skill,level;
		mapping buff;

		if (userp(me))
			return notify_fail("这样技能已经失传了。\n");

		level = me->query("annie/snowforce_budongzhijie");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;

        skill = me->query_skill("snowforce",1);

		if (skill < 30)
        	return notify_fail("『不动之界』需要至少30级的冷雪心经。\n");

		if (me->query("class") != "moon")
			t = 80;
		else
			t = (140-skill)/2;

		if (me->query("timer/solidstat") + t > time())
        	return notify_fail("你短时间里还无法重新施出『不动之界』。\n");

		if( ANNIE_D->check_buff(me,"blocked")) 
			return notify_fail("你现在正在施展类似的能力。\n");

		if (level)
		{
			if(me->query("force") < 50 )    
				return notify_fail("你的内力不够。\n");
	        me->add("force", -50);
		}
		else
		{
			if(me->query("force") < 100 )
				return notify_fail("你的内力不够。\n");
	        me->add("force", -100);
		}

		me->set("timer/solidstat",time());

		buff =
			([
				"caster":me,
				"who":me,
				"type":"blocked",
				"att":"bless",
				"name":"冷雪心经·不动之界",
				"time":me->query("class") != "moon"?10:30,
				"buff_msg":HIR BLK"$N将冷雪心经运遍大小周天，只觉心静如水，浑然不为外力所动。\n"NOR,
			]);
		ANNIE_D->buffup(buff);

        return 1;
}
