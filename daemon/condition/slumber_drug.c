// drunk.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + me->query("max_force")/50)* 2;

	duration --;
	if( duration <1 ) {
		tell_object(me, "蒙汗药的药性终于过去了。\n");
		return 0;
	}
		
	if( duration > random (limit) && living(me) ) {
		me->unconcious();
		return 0;
	} else if( duration > random (limit/2)) {
		tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。\n");
		message("vision", me->name() + "摇头晃脑地站都站不稳，显然是什么药的药力发作了。\n",
			environment(me), me);
	}

	me->apply_condition("slumber_drug", duration);
	
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

string cont_name()	{ return "蒙汗药"; }

int shown_stat()	{ return 1;}	