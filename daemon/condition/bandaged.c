// bandaged.c

inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	int amount;
	
	amount = me->query_skill("manjianghong",1) > me->query_temp("pfm/bandaged") ?
				me->query_skill("manjianghong",1) : me->query_temp("pfm/bandaged");
	
	if (me->query("eff_kee")< me->query("max_kee")) {			
		tell_object(me, YEL"你身上的外伤好了一些！（＋"+(amount+ 10)+"）\n" NOR );
		me->receive_curing("kee", 10 + amount);
	}
	
	duration --;
	
	if( duration < 1)
    {
		tell_object(me, WHT"裹伤的功效消失了！\n" NOR );
		return 0;
	}
	me->apply_condition("bandaged", duration);	    
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

string cont_name()	{ return "裹伤"; }

int shown_stat()	{ return 1;}	