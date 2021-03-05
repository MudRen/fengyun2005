// bat_poison.c

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 140);
	me->receive_wound("gin", 140);
	me->set_temp("last_damage_from","中五花毒身亡。");
	tell_object(me, RED "你中的五花毒发作了，满眼看到的都是色彩斑斓的花朵在飞旋！\n" NOR );
    
    duration --;
    if( duration < 1 ) {
    	tell_object(me, HIG "你中的五花毒终于发作光了！\n" NOR );
    	return 0;
    }	
	me->apply_condition("five-flower", duration);
	
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
	return LOW_POISON;
}


string cont_name()	{ return "五花毒"; }

int shown_stat()	{ return 1;}	