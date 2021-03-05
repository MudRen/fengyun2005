#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{

	me->receive_wound("sen", 20);
	me->receive_damage("kee", 10);
	me->set_temp("last_damage_from","中火玫瑰毒身亡。");
	tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "发作了！\n" NOR );
	
	duration --;
	if( duration < 1 )
    {
		tell_object(me, HIG "你中的" HIR "火玫瑰毒" NOR "终于发作光了！\n" NOR );
		return 0;
	}	
	me->apply_condition("rose_poison", duration);
	
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
	return MID_POISON;
}

string cont_name()	{ return "火玫瑰毒"; }

int shown_stat()	{ return 1;}	