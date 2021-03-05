#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	
	me->receive_wound("gin",10);
	me->receive_wound("sen",10);
	me->set_temp("last_damage_from","抽烟过度，生痨病死了。");
	if (!random(3)) {
		tell_object(me, WHT "你觉得嗓子发干发痒，\n" NOR );
		message_vision(WHT"$N喉咙里咕咕作响，扑地一声吐出一口浓痰！\n" NOR,me );
	}
    
    duration --;
    if( duration < 1 ) {
		tell_object(me, HIG "你的咳嗽终于好点了！\n" NOR );
		return 0;
	}
	me->apply_condition("cough", duration);
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
	return GENERIC;
}

string cont_name()	{ return "咳嗽"; }

int shown_stat()	{ return 1;}	