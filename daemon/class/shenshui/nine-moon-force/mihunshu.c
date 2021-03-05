// silencer@fy4: a high success rate busy skill with 7 round timer.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int skill, per, base, mod, damage, duration, cost;

	if( me->query("class") != "shenshui" ) {
		return notify_fail("迷魂术是神水宫的绝技！\n");
	}
	skill = me->query_skill("nine-moon-spirit", 1);
	if( skill < 50 ) {
		return notify_fail ("迷魂术需要５０级姹女神功。\n");
	}
	duration = me->query("timer/mihunshu") + 14 - time();
	if( duration > 0 ) {
		return notify_fail(HIM"需等待"+duration+"秒才能再次使用迷魂术。\n"NOR);
	}
	cost = skill/2;
	if( cost < 50 ) {
		cost = 50;	
	}
	if( (int)me->query("force") < cost ) {
		return notify_fail("迷魂术至少需要"+cost+"点内力。\n");
	}
	if( !target || target == me ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("迷魂术只能对战斗中的对手使用。\n");
	}
	mod = COMBAT_D->can_busy(me, target, "nine-moon-force");	
	if( !mod ) {
		return notify_fail(HIW"此人功力深湛，不会被迷魂术迷惑的。\n"NOR);
	}
	if( userp(me) ) {
		me->add("force", -cost);
	}
	me->set("timer/mihunshu", time());
	message_vision(HIG"\n$N"HIG"停住了手，用飘飘的眼光温柔地瞧着$n"+HIG"，媚眼如丝，巧笑盈盈 ...\n\n"NOR
					WHT"$N"NOR+WHT"缓缓将手前伸，这只手纤细、柔美，而毫无瑕疵，带着种凄秘的妖艳之气。\n\n\n" NOR, me, target);

	if( !COMBAT_D->do_busy_attack( me, target, "nine-moon-force/mihunshu", "rev-unarmed", 100, mod) ) {
		message_vision(HIY"$N"HIY"避开$n"HIY"的目光，就势斜斩"HIY"$n脉门！\n"NOR, target, me);
		return 1;
	}
	message_vision(HIM"一时之间，$N"+HIM"心中一荡，似已将窒息．眼勾勾地看着$n"+HIM"的纤纤手指拂过胸前。\n\n"NOR, target, me);
	message_vision(RED"$N"NOR+RED"心头如针刺般剧痛，幽幽寒气渗入血脉。\n\n"NOR,target);

	// 200 + random(skill) = 200 + random(200)
	damage = skill + random(skill);
	damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
	damage = damage*(100+10*F_ABILITY->check_ability(me,"3_mihun_add",3))/100;

	target->receive_damage("sen", damage, me);
	target->receive_damage("kee", damage, me);
	target->set_temp("damaged_during_attack", 1);
	target->force_busy(1);

	COMBAT_D->report_status(target);
	COMBAT_D->win_lose_check(me, target, 1);

	return 1;
}


