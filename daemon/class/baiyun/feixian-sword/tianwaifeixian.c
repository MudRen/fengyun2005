//	The purpose of this perform is to busy, not to damage.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	int i, force;
	object weapon;
	
	if ( me->query("class")!="baiyun")
		return notify_fail("只有白云城弟子才会『天外飞仙』的绝技。\n");
		
	if ((string) me->query_skill_mapped("dodge") != "feixian-steps")
		return notify_fail("『天外飞仙』只能和飞仙步法配合！\n");
	
	if (userp(me))
	if (me->query_skill_mapped("force") != "chessism")
		return notify_fail("『天外飞仙』需要弈道心法配合。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『天外飞仙』只能对战斗中的对手使用。\n");
		
	extra = me->query_skill("feixian-sword",1) / 20;
	extra += me->query_skill("feixian-steps",1) /20;
	
	if (extra > 20) extra = 20;
	
	me->add_temp("apply/attack", extra*4);	
	me->add_temp("apply/damage", me->query_skill("feixian-sword",1)/2);
	me->set_temp("in_feixian_pfm",1);
	weapon=me->query_temp("weapon");
	
	msg = HIR  "$N脚踏飞仙步法，剑走轻灵，使出飞仙剑法中的精髓－－『天外飞仙』
手中的"+ weapon->name() +HIR"划出一道长虹，闪电般的击向$n！" NOR;

	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
//	msg =  HIY "剑光如虹，转瞬即逝！\n" NOR;
//        message_vision(msg, me, target);
	
	for(i=0;i< extra/5;i++)
	{
		msg = HIY "剑光如虹，转瞬即逝！$N身形突转，御剑回飞！\n" NOR;
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	}
	
	me->add_temp("apply/attack", -extra*4);
	me->add_temp("apply/damage", -me->query_skill("feixian-sword",1)/2);
	me->delete_temp("in_feixian_pfm");
	
	me->perform_busy(2);
	return 1;
}


