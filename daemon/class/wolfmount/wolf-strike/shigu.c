// Silencer@fengyun workgroup	June.2005
//	atk = 250, dmg = 450

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill, atk, dmg, ratio, dmg_rate;

	skill = me->query_skill("wolf-strike", 1);
	if( skill < 50 || me->query_skill("summonwolf",1) < 50 ) { 
		return notify_fail(" 『嗜骨』需要50级的天狼百破拳和50级的唤狼术！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『嗜骨』只能对战斗中的对手使用。\n");
	}

	dmg_rate = 100 + F_ABILITY->check_ability(me, "3_shigu_add", 3) * 5;
	atk = (50+skill)*dmg_rate/100;
	dmg = (50+skill*2)*dmg_rate/100; 

	// atk = 250, dmg = 450
	msg = HIW "$N双目红赤，大张着手臂，呲着白森森的牙向$n的身上咬去！\n"NOR;
	message_vision(msg, me, target);

	ratio = 30+F_ABILITY->check_ability(me,"shigu_add")*2; 

	if( ANNIE_D->check_buff(me, "bloodthirsty") > 0 ) {
		ratio = ratio * 2;
	}
	me->add_temp("damage_to_heal", ratio);
	me->add_temp("apply/attack", atk);
	me->add_temp("apply/damage", dmg);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	me->add_temp("apply/attack", -atk);
	me->add_temp("apply/damage", -dmg);
	me->add_temp("damage_to_heal", -ratio);
	me->perform_busy(2); 
	return 1;
}