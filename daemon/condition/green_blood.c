// snake_poison.c

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 20);
    me->receive_wound("gin", 20);
    me->receive_wound("sen", 20);
    me->set_temp("last_damage_from","中碧血蛊身亡。");
	tell_object(me, HIW "你中的" HIG "碧血蛊" HIW "发作了！\n" NOR );
	    
    duration --;
    if( duration < 1 ){
		tell_object(me, HIW "你中的" HIG "碧血蛊" HIW "终于发作光了！\n" NOR );
		return 0;
	}
	
	me->apply_condition("green_blood", duration);
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

string cont_name()	{ return "碧血蛊"; }

int shown_stat()	{ return 1;}	