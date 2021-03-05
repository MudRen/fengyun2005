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
	
	extra = me->query_skill("shortsong-blade",1);
	weapon=me->query_temp("weapon");
	
	if ( extra < 150) 
		return notify_fail("『长梦』需要150级短歌刀法！\n");
	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("『长梦』需要棋道心法的配合！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『长梦』只能对战斗中的对手使用。\n");
	
	message_vision(HIY"$N长啸一声，凌空而起，钢刀又化长虹击下，“白首送春拚一醉，东风吹破千行泪”\n"NOR, me, target);
	
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