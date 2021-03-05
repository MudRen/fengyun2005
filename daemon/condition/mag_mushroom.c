#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
    me->receive_wound("kee", 200);
    me->receive_wound("gin", 100);
    me->receive_wound("sen", 100);
    me->set_temp("last_damage_from","中瘴气毒发身亡。\n");
    tell_object(me, HIM "你胃里一阵绞痛，脸上紫气郁结，冒出豆大的黑紫色汗珠！\n" NOR );
    message("vision", me->name() + "右手按住胃部，脸上紫气郁结，头上冒出豆大的黑紫色汗滴！\n", 
			environment(me), me);
    
    duration --;
    if( duration < 1 ) {
    	tell_object(me, YEL "你吐出一口浊气，终于感觉舒坦了许多！\n" NOR );
		return 0;
    }
	
	me->apply_condition("mag_mushroom", duration);
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
	return MID_POISON;
}

string cont_name()	{ return "瘴气"; }

int shown_stat()	{ return 1;}	