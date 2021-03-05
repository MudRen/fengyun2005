/* 这个是给火沼泽房间的设置

等级越高。。这个就死得越快，防止搞经验者robot这个地方

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("zhaoze",10);
}

*/

#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration) 
{
	int level,damage;
	
	if (!userp(me) && !userp(me->query("possessed")))	return 0;
	
	if (environment(me)->query("outdoors")=="zhaoze") {
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		damage = (level>70)? level : 0;
		damage = COMBAT_D->magic_modifier(me, me, "kee", damage + random(level*2)+ 10);
		me->receive_wound("kee", damage);
		me->set_temp("last_damage_from","在火沼泽烈火焚身而死。\n");
		tell_object(me,HIR "\n\n地下的泥土突然裂开，一团炽热的地火象喷泉般射出！！\n"NOR);
		COMBAT_D->report_status(me,1);
		return 1;
	}
	return 0;
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

string cont_name()	{ return "火窟"; }