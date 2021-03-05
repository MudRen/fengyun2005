// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill,t,level,duration;
		object iceshield;

    	if (me->query("class") != "moon")
        	return notify_fail("只有皓月宫中人才能施展『冰魄晶壁』。\n");

		skill = me->query_skill("snowforce",1);
		if (skill < 120 && userp(me))
        	return notify_fail("『冰魄晶壁』需要至少120级的冷雪心经。\n");
        
/*冰魄晶壁?第一卷	snowforce_bingpojingbi_1 L100	1M, 10%
冰魄晶壁?第二卷	snowforce_bingpojingbi_2 L120	2.4M	20%
冰魄晶壁?第三卷	snowforce_bingpojingbi_3 L140	4M		30%
冰魄晶壁?第四卷	snowforce_bingpojingbi_4 L160	6.4M	30%

*/
		level = me->query("annie/snowforce_bingpojingbi");
		if (!userp(me))
			level = 5;

		if (!level)
        	return notify_fail("你尚没有领悟冷雪心经中的『冰魄晶壁』。\n");

		t = 60;		// same as iceshield expiration time
		duration = me->query("timer/iceshield")+t -time();
		if (duration >0 && userp(me))			
        	return notify_fail("『冰魄晶壁』还需要等待"+duration+"秒钟。\n");

        if(present("ice shield",me)) 
        	return notify_fail("你已经在运功中了。\n");

		if(me->query("force") < 100 && userp(me))   
			return notify_fail("『冰魄晶壁』需要100点的内力。\n");
		if (userp(me))
	        me->add("force", -100);

		me->set("timer/iceshield",time());
		seteuid(getuid());

		iceshield=new("/obj/specials/moon/iceshield");

		message_vision(HIW"$N"HIW"运转心诀，层层寒雾在身边笼聚，渐渐凝成一面冰晶之壁！\n"NOR,me);

		if (!iceshield->move(me))
		{
			message_vision(WHT"然而$N"NOR+WHT"稍一舒气，晶壁就化成水雾，消散无形。\n\n"NOR,me);
			return 1;
		}
		iceshield->protect(me,level);
		
		if (userp(me))	me->perform_busy(2);
		
        return 1;
}

