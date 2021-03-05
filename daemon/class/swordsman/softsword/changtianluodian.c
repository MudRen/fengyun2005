// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,skill;
	object weapon;
	if(me->query("class")!="swordsman")
		return notify_fail("神剑只有剑神的弟子才有资格用！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［长天落电］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("sword") *2;
	skill = me->query_skill("softsword",1);
	
	if(skill<150)
		return notify_fail("你清风细雨温柔剑法的修为不够。\n");
		
	target->delete_temp("last_damage_from");
	me->set_temp("cut_mana",1);
	me->add_temp("apply/attack", extra/4);	
	me->add_temp("apply/damage", extra);
	msg =  HIC"\n"+weapon->name()+ HIC"凌空而起，化做一道光华，一道曲折延伸的光华、璀璨、辉煌、美丽。 \n"
HIW "光华在闪动、变幻、高高在上，轻云飘忽，霎那间这道光华已就在$n 
眉睫间!它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。\n "NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra/4);
	me->add_temp("apply/damage", -extra);
	me->perform_busy(3);
	me->delete_temp("cut_mana");
	return 1;
}
