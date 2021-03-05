// Silencer@fy4 workgroup
// Add 75%-125% force instantly every 15mins.
//	心动而力发，一攒一放，自然而施，不觉其出而自出，如潮之涨，似雷之发。

#include <ansi.h>

int exert(object me, object target)
{
	int extra,force, max_force, bonus, duration;
	
	if(me->query("class")!="shaolin")
		return notify_fail("只有少林高僧才能使用『三藏净身』\n");
	
	extra=me->query_skill("yijinjing",1);
	if(extra<200)
		return notify_fail("需要200级易筋经才能使用『三藏净身』\n");

	duration = me->query("timer/pfm/sl_sanzang")-time()+ 900;
    if (duration>0)
       	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『三藏净身』。\n");

	message_vision(BGRN + WHT"$N运起易筋经之三藏净身，内力一攒一放，自然而施，不觉其出而自出，如潮之涨，似雷之发。\n"NOR,me);
	force = me->query("force");
	max_force = me->query("max_force");
	
	bonus = max_force * (75 + F_ABILITY->check_ability(me,"sanzang_add")*5) /100;
	
	if ( force + bonus > 2* max_force)	
		me->set("force",2*max_force);
	else
		me->add("force",bonus);
		
	me->force_status_msg("force");
	me ->set("timer/pfm/sl_sanzang",time());
	return 1;
}


