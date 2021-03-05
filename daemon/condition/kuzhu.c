#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_curing("sen", 100);
	message_vision("$N的神情一凛，精神似乎又好了一些。\n",me);
	
	duration --;
	if( duration < 1 ) 
		return 0;
	me->apply_condition("kuzhu", duration);
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
	return NO_CURE;
}

string cont_name()	{ return "苦竹提神"; }

int shown_stat()	{ return 1;}	