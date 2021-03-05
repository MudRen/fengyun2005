#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration){

      if(environment(me)->query("indoors") == "huashan" 
             ||     environment(me)->query("outdoors") == "huashan") {
      		message("vision", "幽幽的琴声时断时续，有时如夜阑轻语，有时如滴水落檐，不时从山顶飘下来。\n" NOR,environment(me));
             	me->apply_condition("music", duration - 1);
        	if( duration < 1 ) return 0;
       } else {    
              me->change_condition_duration("music",0);
       }
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

string cont_name()	{ return "琴声"; }