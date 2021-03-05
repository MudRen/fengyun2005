// Silencer@fengyun	June.2005
//	shaolin: +atk 85, +dmg 0, 170, 340

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int skill, extra_attack, extra_damage, busy;
	object weapon;
	skill = me->query_skill("wuche-axe", 1);
	if( userp(me) && skill < 150 ) {
		return notify_fail("『三板斧』需要150级的悟彻波风斧法！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『三板斧』只能对战斗中的对手使用。\n");
	}
	extra_attack = skill/2;
	extra_damage = skill;
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", extra_attack);
	msg = HIY  "$N"HIY"大喝一声，手中"+weapon->name()+HIY"巨斧凝光，凌空百变，连环数招向$n击出！\n";
	message_vision(msg, me, target);

	msg = HIY"『第一斧』" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);

	msg = HIY  "『第二斧』"NOR;
	me->add_temp("apply/damage", extra_damage);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	me->add_temp("apply/damage", -extra_damage);
    
	if( skill >= 130 ) {
		msg = HIY  "『第三斧』" NOR;
		me->add_temp("apply/damage", 2*extra_damage);
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		me->add_temp("apply/damage", -2*extra_damage);
		busy = 3;
	} else if( !random(5) ) {
		// for player, this is not possible to happen
		tell_object(me,HIG"\n你的手法不够熟练,第三斧没使出来.\n"NOR);
		busy = 2;
	}
	me->add_temp("apply/attack", -extra_attack);
	me->perform_busy(busy);
	return 1;
}
