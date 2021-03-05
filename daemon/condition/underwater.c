/* 这个是给所有水下房间的设置

set("underwater",depth);
set("water_damage",damage);

depth	是衡量水深的数值(1-200),与游泳技术相关。
damage	是每次发作%的kee伤害。(1-100)

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}

*/

#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration) 
{
	int depth,damage;
	string pos, msg;
	
	if (!userp(me))		return 0;
	
	if (depth = environment(me)->query("underwater")) {
		if (me->query_temp("apply/use_under_water")>=depth) 	//具有游泳用品
			return 1;
		damage = environment(me)->query("water_damage") ? 
				environment(me)->query("water_damage") : 100;
		me->receive_damage("kee",me->query("max_kee") * damage /100);
		pos = environment(me)->query("short")?environment(me)->query("short"):"水里";
		me->set_temp("last_damage_from","在"+pos+"淹死了。\n");
		
		switch ( me->query("kee") * 100 / (me->query("max_kee") + 1) ) {
			case -100..20:  msg = HIR"$N已经憋得成半昏迷状态，再不离开恐怕就没命了。\n"NOR;	break;
			case 21..50: msg = RED"$N已经憋得面红耳赤，上气不接下气。\n"NOR;		break;
			case 51..80: msg = WHT"$N咕嘟咕嘟地又呛了几口水，看来这儿不是久留之地。\n"NOR;	break;
			case 81..200:msg = HIB"$N只觉胸口发闷，透不过气来。\n"NOR;			break;
			default: msg = HIR"$N出问题了，快快报告巫师。\n"NOR; // for hp<0;
		}
		message_vision(msg, me);
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

string cont_name()	{ return "水下"; }

int shown_stat()	{ return 1;}	