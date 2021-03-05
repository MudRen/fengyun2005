#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, mod, count, duration, amount;
	object weapon;

	if( me->query("class") != "moon" ) {
		return notify_fail("只有皓月宫的弟子才能施展『连天衰草』。\n");
	}
	extra = me->query_skill("starrain",1);
	if( extra < 80 ) {
		return notify_fail("『连天衰草』需要至少80级的寒星雨觞。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『连天衰草』只能对战斗中的对手使用。\n");
	}
	duration = me->query("timer/pfm/starrain_sp") + 20 - time();
	if( duration > 0 ) {
		return notify_fail("『红藕香残』、『七星伴月』和『连天衰草』每２０秒钟只能使用一次（还需等待"+duration+"秒）\n");
	}
	if( ANNIE_D->check_buff(target,"lowresist-sen") ) {
		return notify_fail("对方已经受到了相似的影响。\n");
	}
	// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if( count < 6 ) {
		return notify_fail("『连天衰草』至少需要6枚暗器。\n");
	}
	if( userp(me) ) {
		weapon->add_amount(-6);
	}
	me->set("timer/pfm/starrain_sp",time());
	msg = HIG "\n一袭绿光从$N"HIG"手中陡然凌空而飞，就象在暴风雨来临之前迎击苍穹的绿色飞鸟，激射$n。\n"NOR;
	message_vision(msg, me, target);
	if( !COMBAT_D->do_busy_attack(me, target, "starrain/yanzihuishi", "step", 200, 10) ) {
		msg = YEL "$N"NOR+YEL"大喝一声，绿光随着罡风在身周流转飞散。\n"NOR;
		message_vision(msg, target);
	} else {
		amount = -10;
		amount -= F_ABILITY->check_ability(me,"3_ltsc_add",3)*2;
		msg = HIR BLK"绿光轻巧若无物般地落在$N"HIR+BLK"肩上，$N"HIR+BLK"却似被重锤所击，踉踉跄跄地退了数步。\n" NOR;
		buff =
		([
			"caster": me,
			"who": target,
			"type": "lowresist-sen",
			"att": "curse",
			"name":"寒星雨觞·连天衰草",
			"time": 10,
			"buff1": "resistance/sen",
			"buff1_c": amount,
			"buff_msg": msg,
			"disa_msg": WHT"$N"NOR WHT"慢慢地终于缓过神来。\n"NOR,
			"disa_type": 1,
		]);
		ANNIE_D->buffup(buff);
	}
	return 1;
}