// npc_poqi.c 破气式 --- modified to cut force for NPC to use @silencer
 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	 string msg;
	 int skill,ap,dp,tf;

	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
		
	 if( !target ) target = offensive_target(me);
	        if( !target
	        ||      !target->is_character()
	        ||      !me->is_fighting(target) )
	                return notify_fail("『破气式』只能对战斗中的对手使用。\n");
	
	 skill = (int)me->query_skill("dugu-sword",1);
	 //no poqi in fy4 for players-neon
	 if( skill < 100 && userp(me))
	 	return notify_fail("你的独孤九剑等级不够, 不能使用『破气式』！\n");
	
	 msg = HIB "$N暗运独孤九剑『破气式』，一股氤氲正气浩然而出, 当真是剑落鬼神惊！ \n";
	
	 ap =  (int) me->query("combat_exp")* skill/50;
	 dp = (int) target->query("combat_exp");
	 if(random(ap+dp) > dp) {
	 	target->set("force",0);
	 	msg += "$n浑身剧震，诸般大穴似乎都被点中，内力尽失！\n" NOR;
	        me->start_busy(3);
	        target->start_busy(2);
	 }else {
	 	msg += WHT"可是$n看破了$N的剑路，就地一滚，才堪堪躲过。\n" NOR;
	 	me->start_busy(2);
	 }
	 message_vision(msg, me, target);
	 return 1;
}
