// bandaged.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

// average 200 * 10 = 2000 in 200 sec 

int update_condition(object me, int duration)
{
	int amount;
	
	amount = me->query_temp("marks/music-qx");
	if (!amount)
		amount = me->query_skill("music",1);	// if they quit and lose the temp mark
	
	if (me->query("eff_kee")< me->query("max_kee")) {			
		tell_object(me, CYN"真气顺着韵律游走，你浑身舒畅已极！（＋"+ amount+ "）\n" NOR );
		me->receive_fulling("kee", amount);
	}
	
	duration --;
	
	if( duration < 1 )
    {
		tell_object(me, WHT"清心普善的功效消失了！\n" NOR );
		me->delete_temp("marks/music-qx");
		return 0;
	}
	me->apply_condition("qingxin", duration);	    
	return 1;
}

int condition_type()
{
// in condition.h
/*

#define NO_CURE        		10
#define NON_POISON     		9
#define BLOOD_POISON   		8
#define NERVE_POISON   		7
#define BRAIN_POISON   		6
#define OBSCENE_POISON 		5
#define GENERIC			0

*/

	return NO_CURE;
}

string cont_name()	{ return "清心普善"; }

int shown_stat()	{ return 1;}	