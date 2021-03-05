inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 10);
    me->receive_wound("gin", 10);
    me->receive_wound("sen", 10);
	tell_object(me, HIW "你胃里一阵绞痛，头上冒出豆大的汗珠！\n" NOR );
	message("vision", me->name() + "右手按住胃部，面色惨白，头上冒出豆大的汗滴！\n", environment(me), me);
	
	duration --;
	
	if( duration < 1 ) {
			tell_object(me, HIW "你的胃里终于感觉好的多了！\n" NOR );
			return 0;
	}
			
	me->apply_condition("mushroom", duration);
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


string cont_name()	{ return "食物中毒"; }

int shown_stat()	{ return 1;}	