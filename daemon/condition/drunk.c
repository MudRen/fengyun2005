// drunk.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;  // 22-100 for players
	limit = limit /2; // 11-50
	
	duration --;
	
	if (duration < 1)	return 0;
		
	if( duration > limit &&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "打了个嗝儿，不过依然烂醉如泥。\n",
			environment(me), me);
	} else if( duration > limit/2 ) {
		tell_object(me, "你觉得脑中昏昏沉沉，身子轻飘飘地，大概是醉了。\n");
		message("vision", me->name() + "摇头晃脑地站都站不稳，显然是喝醉了。\n",
			environment(me), me);
		me->receive_damage("sen", 10);
	} else if( duration > limit/4 ) {
		tell_object(me, "你觉得一阵酒意上冲，眼皮有些沉重了。\n");
		message("vision", me->name() + "脸上已经略显酒意了。\n",
			environment(me), me);
	}

	me->apply_condition("drunk",duration);
	
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

string cont_name()	{ return "醉酒"; }

int shown_stat()	{ return 1;}	