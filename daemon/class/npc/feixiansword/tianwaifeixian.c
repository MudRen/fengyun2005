#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int busy_target(object me,object target);

int perform(object me, object target)
{
	string msg;
	int extra;
	int i, force;
	object weapon,*pros;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『天外飞仙』只能对战斗中的对手使用。\n");
		
	force = me->query("force_factor");
	me->set("force_factor",0);
	
	extra = me->query_skill("feixiansword",1) / 10;
	
	me->add_temp("apply/attack", extra*4);	
	me->add_temp("apply/damage", me->query_skill("feixiansword",1)/2);
	me->set_temp("in_feixian_pfm",1);
	weapon=me->query_temp("weapon");
	
	msg = HIR  "$N脚踏琴声余韵，剑势陡变，使出飞仙剑法中的精髓－－『天外飞仙』
手中的"+ weapon->name() +HIR"划出一道长虹，闪电般的击向$n！" NOR;

	target->add_temp("buff/no_abs",1);
	pros = target->query_temp("protectors");
	target->delete_temp("protectors");

	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	busy_target(me,target);
	
	for(i=0;i< extra/5;i++)
	{
		msg = HIY "剑光如虹，转瞬即逝！$N身形突转，御剑回飞！" NOR;
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		busy_target(me,target);
	}
	
	me->add_temp("apply/attack", -extra*4);
	me->add_temp("apply/damage", -me->query_skill("feixiansword",1)/2);
	me->delete_temp("in_feixian_pfm");
	me->set("force_factor",force);

	if (target) {
		target->add_temp("buff/no_abs",-1);
		target->set_temp("protectors",pros);
	}
	
	me->perform_busy(2);
	return 1;
}

int busy_target(object me,object target)
{
	if (!target->query_temp("damaged_during_attack")) 
	{
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N凝定心神，劲力暗送，迫开$n，转眼间重夺先机。\n"NOR,me,target);
			me->stop_busy();
		}
		else
		{
			message_vision(WHT "剑风中真力贯注，沉重难挽，与飞仙轻灵大异其趣，$n勉力挡开此剑，已是手脚酥麻。\n"NOR,me,target);
			if (target->query("force"))
			{
				target->add("force",-200);
				if (target->query("force") < 0)
					target->set("force",0);
			}
			else
				target->force_busy(1+target->query_busy());
		}			
	}
	return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

