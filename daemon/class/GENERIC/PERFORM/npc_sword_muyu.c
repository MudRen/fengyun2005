// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int extra, int skill);
int perform(object me, object target)
{
	string msg;
	int extra, skill,resist;
	object weapon;
	
	if(userp(me)&& !wizardp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
			
	if(me->query("class")!="swordsman")
		return notify_fail("神剑只有剑神的弟子才有资格用！\n");
	
	if(me->query_skill("softsword",1)<50)
		return notify_fail("你清风细雨温柔剑法的修为不够。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［暮雨飞虹］只能对战斗中的对手使用。\n");

			
	weapon = me->query_temp("weapon");
	
	extra = me->query_skill("sword");
	skill = me->query_skill("softsword",1);
	
	target->delete_temp("last_damage_from");
	
	me->add_temp("apply/attack", skill);	
	me->add_temp("apply/damage", extra);
	msg = HIC "$N一剑挥出，如夕阳，又如烈日，如彩虹，又如乌云，如动又静，如虚又实，
如在左，又在右，如在前，又在後，如快又慢，如空又实。 \n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -extra);
	
	if(target->query_temp("last_damage_from") && (!userp(me) || skill>170)) {
		msg=HIW"剑光如飞虹，森寒的剑气，冷得深入骨髓。\n"NOR;	
       		me->add_temp("apply/attack", skill*3);    
       		me->add_temp("apply/damage", extra*2);		
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack", -skill*3);
       		me->add_temp("apply/damage", -extra*2);
       		if (me->query_busy()<3) me->start_busy(3);
		}
	else {
		if (me->query_busy()<2) me->start_busy(2);
		}
	return 1;
}
