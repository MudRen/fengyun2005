#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	object obj,owner;
	int duration, sk = me->query_skill("heart-listening",1);
	int a=0;

	if(me->query("class")!="moon" && userp(me))
		return notify_fail("只有皓月宫中人才能够施展『遗心忘恨』。\n");

	if(me->query_skill("heart-listening",1) < 80 && userp(me))
		return notify_fail("『遗心忘恨』至少需要80级幻念聆音。\n");

	duration = me->query("timer/hypnosis")+ 120 - time();
	if (duration > 0)
       	return notify_fail("『遗心忘恨』还须等待"+duration+"秒钟。\n");
	
	// NPC self-remove-hate-list hehe :)
	if (!userp(me))	{
		target = me;
		message_vision(WHT"\n$n"WHT"避开一势，身形后闪，右手二指轻轻按在眉心，脸上露出一抹笑意。\n"NOR,target,me);
		target->reset_hate();
		return 1;
	}
	
	if( !target ) target = offensive_target(me);        
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target)  || !target->is_fighting(me))
			return notify_fail("这种法术只能对战斗中的对手使用。\n");

	if (me->query("mana") < 150  && userp(me))
		return notify_fail("你的法力不够。\n");
	if (userp(me))
		me->add("mana",-150);
	me->set("timer/hypnosis",time());
		
	message_vision(WHT"\n$n"WHT"避开一势，身形后闪，右手二指轻轻按在眉心，脸上露出一抹笑意。\n"NOR,target,me);
	
	if (COMBAT_D->do_busy_attack(me, target, "heart-listening", "unarmed", 1000, 10)) {
		message_vision(BLU"\n$N"BLU"脑海中神思电闪，刹那间化入混沌，茫然无措地望向$n"BLU"。\n\n"NOR,target,me);
		target->reset_hate();
	} else
		message_vision(YEL"$N冷笑一声，不为$n的幻招所动！\n"NOR, target,me);
		
	me->perform_busy(2);
	return 1;
}



/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
