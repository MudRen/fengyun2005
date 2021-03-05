#include <ansi.h>
#include <condition.h>


inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("gin", 30);
	me->receive_wound("kee", 30);
	me->receive_damage("sen", 30);
	me->set_temp("last_damage_from","中九阴化骨毒身亡。");
	tell_object(me, HIB "你全身渗出血红色的汗珠，你中的九阴化骨毒发作了！\n" NOR );
	
	duration --;
	if( duration < 1 ) {
		tell_object(me, YEL"你中的九阴化骨毒终于发作完了。\n"NOR);
		return 0;
	}
	
	me->apply_condition("ninemoonpoison", duration);
	return CND_CONTINUE;
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


string cont_name()	{ return "九阴化骨毒"; }

int shown_stat()	{ return 1;}	