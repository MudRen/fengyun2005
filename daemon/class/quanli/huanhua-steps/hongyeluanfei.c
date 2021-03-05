// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[红叶乱飞秋千去]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("[红叶乱飞秋千去]只能和浣花剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("[红叶乱飞秋千去]只能和浣花剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "huanhua-sword")
	return notify_fail("[红叶乱飞秋千去]只能和浣花剑法配和！\n");
	
	extra = me->query_skill("huanhua-sword",1) ;
	extra += me->query_skill("huanhua-steps",1);
	
	me->add_temp("apply/attack", extra/2);	
	me->add_temp("apply/damage", extra);
	
	msg = HIR  "$N使出[红叶乱飞秋千去]，暗运内力，震飞手中的"+ weapon->name() +"，剑尖自八方击向$n！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	if (weapon)	weapon->unequip();
	
	msg =  HIW "空中无数剑尖飞向$n．．．．\n" NOR;
        message_vision(msg, me, target);
	
	for(i=0;i<extra/100;i++)
	{
	msg = HIY "$N弃剑换掌，使出浣花派的飞絮掌法，拍向$n的$l！\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	if (weapon) weapon->equip();
	
	me->add_temp("apply/attack", -extra/2);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
