// bat_poison.c

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	tell_object(me, HIG "你中的蝙蝠毒发作了！\n" NOR );
	me->receive_wound("kee", me->query("max_kee")/50);
	me->receive_wound("sen", me->query("max_sen")/50);
	me->set_temp("last_damage_from","中蝙蝠毒身亡。");
	
	duration --;
	if( duration < 1 )
    {
		tell_object(me, HIG "你中的蝙蝠毒终于发作光了！\n" NOR );
		return 0;
	}
	me->apply_condition("bat_poison", duration);	    
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

string cont_name()	{ return "蝙蝠毒"; }

int shown_stat()	{ return 1;}	