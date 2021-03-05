inherit F_CLEAN_UP;  
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	duration --;
	if (duration <1)	return 0;
	
	if( duration > random(limit) &&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( duration > random(limit/2) ) {
		tell_object(me, "你觉口中又苦又咸，真的受不了了！\n");
		message("vision", me->name() + "嘴唇发白，似乎极度脱水了！\n",
			environment(me), me);
	}
	me->apply_condition("salt_drug", duration);
	
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

string cont_name()	{ return "脱水"; }

int shown_stat()	{ return 1;}	