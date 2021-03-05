inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	if(!me->query_temp("block_msg/all"))
	{
		tell_object(me, HIW"你只觉得眼前白茫茫的一片，什么都看不见了。\n" NOR );
		me->add_temp("block_msg/all",1);
	}

	duration --;
	if (duration<1)
	{
		if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
		tell_object(me, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
		return 0;
	}
	me->apply_condition("blind", duration);	
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


string cont_name()	{ return "失明"; }

int shown_stat()	{ return 1;}	