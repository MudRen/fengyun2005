// qicaibat.c  七彩蝙蝠毒

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{

	
	tell_object(me, HIG "你中的七彩蝙蝠毒发作了！\n" NOR );
	me->receive_wound("kee", 150);
	me->receive_wound("sen", 100);
	me->set_temp("last_damage_from","中七彩蝙蝠毒身亡。");
		
	duration --;
    if( duration < 1 )
    {
		tell_object(me, HIG "你中的七彩蝙蝠毒终于发作光了！\n" NOR );
		return 0;
	}
	me->apply_condition("qicaibat", duration);
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

string cont_name()	{ return "七彩蝙蝠毒"; }

int shown_stat()	{ return 1;}	