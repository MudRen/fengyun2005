#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{	
	me->receive_wound("kee", 50);
    me->receive_wound("gin", 50);
    me->receive_wound("sen", 50);
    me->set_temp("last_damage_from","中无名毒神秘身亡。");
    tell_object(me, HIW "你身上的毒素发作了！\n" NOR );
    
    duration --;
	if( duration < 1 )
    {
		tell_object(me, HIW "你身上不知中的什么毒终于发作光了！\n" NOR );
		return 0;
	}
	
	me->apply_condition("unknown", duration);
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

string cont_name()	{ return "无名毒"; }

int shown_stat()	{ return 1;}	