// mind_sense.c by silencer@fy4

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	string *vis = ({ "『形』", "『神』", "『俱』", "『灭』" });
	int cost, damage, skill, dp, bonus, n, i;
	int force_rate;

	if( me->query("class") != "bonze" ) {
		return notify_fail("只有兴国禅寺的弟子才可以使用『神识』\n");
	}
	skill = me->query_skill("essencemagic",1);
	if( skill < 40 ) {
		return notify_fail("『神识』需要40级八识神通！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("这种法术只能对战斗中的对手使用。\n");
	}
	cost = skill/2;
	if( cost < 50 ) {
		cost = 50;
	}
	if( (int)me->query("atman") < cost ) {
		return notify_fail("『神识』需要"+cost+"点灵力！\n");
	}
	me->add("atman", -cost);
	msg = HIY "$N闭目凝神，印堂飞起一片红霞，猛然间佛光耀眼，四五道金霞银虹刺向$n！\n\n" NOR;
	message_vision(msg, me, target);
	// 600+ random(400) --> L220: 430*3/2 + random(430) = 645 + random (430)
	damage = me->query_skill("magic");
	damage = damage*3/2 + random(damage);
	if( ANNIE_D->check_buff(me, "xg-evil") ) {
		damage = damage*(150+F_ABILITY->check_ability(me,"3_zhuxian_add",3)*2)/100;
	}
	damage = COMBAT_D->magic_modifier(me, target, "kee", damage/4);
	if( skill > 200 ) {
		skill = 200;
	}
	me->add_temp("apply/magic", skill*2);
	for( i = 0; i < 4; i++) {
		if( COMBAT_D->do_magic_attack(me, target, "magic", "kee") ) {
			message_vision(HIC"  "+vis[i]+NOR,me, target);
			target->receive_damage("kee", damage, me);
			COMBAT_D->report_status(target);
			force_rate = F_ABILITY->check_ability(me,"3_mind_add",3)/2;
			if( me->query_skill("essencemagic",1) >= 200 ) {
				force_rate += 10;
			}
			if( force_rate > 0 ) {
				if( me->query("force") + damage*force_rate/100 < 2*me->query("max_force") ) {
					me->add("force", damage*force_rate/100);
				} else {
					me->set("force", me->query("max_force")*2);
				}
				me->force_status_msg("force");
			}
		} else {
			message_vision(HIC"  "+vis[i]+NOR,me, target);
			msg = YEL"( 但是被$n机灵地躲开了)\n"NOR;
			message_vision(msg, me, target);
		}
	}
	me->add_temp("apply/magic", -skill*2);
	COMBAT_D->win_lose_check(me, target, damage);
	message_vision("\n\n", target);
	me->perform_busy(2);
	return 1;
}