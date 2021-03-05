#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   	mapping exits;
    	string *dirs;
    	
	duration--;
	if( duration < 0 )	{
		me->set_temp("marks/ready_incar",1);	
		tell_object(me, HIR"你浑身颤抖，恍若大梦初醒，前生的种种切切似乎已成了传说。\n"NOR);
		return 0;
	}
	
	if(environment(me))
	if(mapp(exits = environment(me)->query("exits"))) {
    		tell_object(me, WHT"你心中忽然涌起莫名伤感，只觉悲苦凄凉，茫然不知何往。\n"NOR);
    		message("vision", me->name() + "面容凄苦，失神一般漫无目的地乱走。\n",	environment(me), me);
	    	dirs = keys(exits);
    		me->ccommand("go " + dirs[random(sizeof(dirs))]);
	}
	me->apply_condition("mengpo", duration);
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

string cont_name()	{ return "伤逝"; }

int shown_stat()	{ return 1;}	