// drunk.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + me->query("max_force")/50)* 2;

	duration --;
	if (duration < 1) 	return 0;
		
	if( duration > limit&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "的花柳毒又发作了．．。\n",
			environment(me), me);
	} else if( duration > limit/2 ) {
		tell_object(me, "你觉得全身又痛又痒。\n");
		message("vision", me->name() + "的花柳毒又发作了，满面痛苦后悔的表情。\n",
			environment(me), me);
	} else if( duration > limit/4 ) {
		tell_object(me, "你觉得全身又痛又痒。\n");
		message("vision", me->name() + "的花柳毒又发作了，满面痛苦后悔的表情。\n",
			environment(me), me);
	}

	me->apply_condition("hualiu_poison", duration);
	
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

string cont_name()	{ return "花柳毒"; }

int shown_stat()	{ return 1;}	