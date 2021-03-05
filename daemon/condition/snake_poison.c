
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	
	tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
	me->receive_wound("kee", me->query("max_kee")/20);
	me->receive_wound("sen", me->query("max_sen")/20);
	me->set_temp("last_damage_from","中蛇毒身亡。");
	
	duration --;
	if( duration < 1 )
    {
		tell_object(me, HIG "你中的蛇毒终于发作光了！\n" NOR );
		return 0;
	}
	me->apply_condition("snake_poison", duration);
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

string cont_name()	{ return "蛇毒"; }

int shown_stat()	{ return 1;}	