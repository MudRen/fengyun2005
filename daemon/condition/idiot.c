#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	int i;
	i = me->query("sen");
	if( i > 21) {	
		me->receive_damage("sen", 20);
    	}
   	if( random(7) < 2 ) {
	    	tell_object(me, YEL"你发现天下万理莫过如此，人人不过都是傻子罢了。\n"NOR);
	    	message("vision", me->name() + "目光呆滞，嘴角挂着长长的哈拉子~~~~~~\n",environment(me), me);
	}
	me->apply_condition("idiot", duration-1);
	if( duration < 1 ) return 0;
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

string cont_name()	{ return "傻呼呼"; }

int shown_stat()	{ return 1;}	