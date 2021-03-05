
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
	me->receive_wound("kee", 100);
	me->set_temp("last_damage_from","被苍鹰抓伤，伤重难治，失血过多身亡。\n");
	tell_object(me, HIR"苍鹰的利爪抓破了你的手臂。你的胳膊上不停地流血。\n" NOR );
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
	return NO_CURE;
}


string cont_name()	{ return "苍鹰抓伤"; }