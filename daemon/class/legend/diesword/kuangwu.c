// Silencer@fengyun	June.2005
//	inherent +20% from six-sense
// no +atk, +dmg, 1st 100, 2nd 100, 3rd 500+200
//	compared to FY4 1st 150, 2nd 150, 3rd 1100

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,apply, dmg, n;
	object weapon;
	
	extra = me->query_skill("diesword",1);
	weapon=me->query_temp("weapon");
	
	if ( extra < 150) 
		return notify_fail("『狂舞』需要150级蝶恋花剑法！\n");
	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("『狂舞』需要棋道心法的配合！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『狂舞』只能对战斗中的对手使用。\n");
	
	message_vision(HIG"$N脚步微错，青锋回旋，剑身不住颤动，剑光又一闪，“莫怪月满不留君，留君最属君庭月”\n"NOR, me, target);
	
	
		
	if (me->query_temp("pfm/tx-hit-parried") + 10 > time()) {
		me->delete_temp("pfm/tx-hit-parried");
		me->add_temp("apply/attack",extra*3);
		me->add_temp("apply/damage",extra*2);
		target->add_temp("cant_parry",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->add_temp("cant_parry",-1);
		me->add_temp("apply/damage",-extra*2);
		me->add_temp("apply/attack",-extra*3);	
	}
	else	{
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->perform_busy(2);		
	}
	
	return 1;	
}