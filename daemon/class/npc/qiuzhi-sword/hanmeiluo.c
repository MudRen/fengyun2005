// mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int second_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	extra = me->query_skill("qiuzhi-sword",1);
	weapon=me->query_temp("weapon");
	if ( extra < 100) return notify_fail("你的虬枝剑式还不够纯熟！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［寒梅落］只能对战斗中的对手使用。\n");
	
	msg = HIG "$N手中"+weapon->name()+HIG"沿着一道奇古而又自然轨迹缓缓摆动，空气中忽然有一种清冽的感觉。\n"NOR ;
	msg+= WHT "一缕缕微寒的淡淡幽香似乎从虚无中幻出，若有若无。\n" ;
	message_vision(msg,me);
	
	/*
	if(random(me->query("combat_exp")+extra*extra*extra)>target->query("combat_exp")/3)
	{
		message_vision(YEL "$N情不自禁地深深吸了一口气，沉迷于淡淡的幽香中。 \n"NOR,target);
		target->force_busy(3);
	}
	else
		message_vision(HIY "$N一凝神，不为缕缕暗香造成的幻像所动。\n"NOR,target);
	*/

	me->add_temp("apply/damage",extra*5);
	msg = HIW "点点光华漩然落下，似梅花又不是梅花，似雪花又不是雪花，飞向$n周围。"NOR ;
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*5);

	if (!target->query_temp("damaged_during_attack"))
	{
		message_vision(HIY "$N避实就虚，在如梅雪飘落的剑影中闪身而出。 \n"NOR,target);
	}	
	me->perform_busy(2);
	return 1;
}
