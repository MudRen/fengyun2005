
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int dam_kee,dam_gin,dam_sen;
	string msg;
	
	dam_kee = (int) me->query("max_kee")/10;
	dam_gin = (int) me->query("max_gin")/10;
	dam_sen = (int) me->query("max_sen")/10;
	me->receive_wound("kee", dam_kee);
    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
    me->set_temp("last_damage_from","受阴阳合和散催情作用，全身爆裂而死。\n");
	tell_object( me, HIR "你中的" HIY "阴阳合和散" HIR  "发作了，你觉得全身燥热不已！\n" NOR );
	msg = me->query("gender") == "男性" ? 
			RED"头颈赤红发热，赤红的一双眼睛充满了欲望，那眼光象要把你扒光。\n"NOR 
			: "娇喘微微，面上泛出一层"RED"桃花般淡淡的红色"NOR MAG"，春情难禁，眼中媚波流动"NOR"，GRN似乎要滴出水来。\n"NOR ;
	message("vision", "只见" + me->name() + msg, environment(me), me);
		
	
    duration --;
    if( duration < 1 )
	{
		tell_object(me, HIR "你终于受不了" HIY "阴阳合和散" HIR "的催情作用，全身爆裂而死！\n" NOR );
		message("vision", me->name() + "全身经脉爆裂。\n", environment(me), me);
		me->die();
		return 0;
	}
	
	me->apply_condition("hehe", duration);
	return 1;
}


int condition_type()
{
// in condition.h
/*

#define NO_CURE        		100
#define SPECIFIC_POISON		30
#define MID_POISON   		20
#define LOW_POISON   		10
#define GENERIC			0

*/
	return SPECIFIC_POISON;
}

string cont_name()	{ return "阴阳合和散"; }

int shown_stat()	{ return 1;}	