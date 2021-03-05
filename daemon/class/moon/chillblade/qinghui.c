// annie 07.2003
// 冰镜刀法 
// 清辉(perform blanche.....*escape)

// 需要在夜晚施展 :pp

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, bonus = 1, level;
	object weapon;

	if( me->query("class") != "moon" ) {
		return notify_fail("只有皓月宫中人才能施展『清辉』。\n");
	}
	if( me->query("gender") == "男性" && userp(me) ) {
		return notify_fail("男子不适合施展冰镜七诀的『清辉』一式。\n");
	}
	if( me->query_skill("chillblade",1) < 190 && userp(me) ) {
		return notify_fail("『清辉』需要至少190级的冰镜七诀。\n");
	}
	if( me->query("max_mana") < 1000 ) {
		return notify_fail("『清辉』需要至少1000最大法力为基础。\n");
	}
	if( userp(me) && !me->query("annie/chillblade_qinghui") ) {
		return notify_fail("『明月』需要先从卷轴上悟出才能使用。\n");
	}
	if( me->query("mana") < 1000 ) {
		return notify_fail("你的法力太低，就算打中了也没有什么效果的。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『清辉』只能对战斗中的对手使用。\n");
	}

/*
	清辉?上册		chillblade_qinghui_1		L150	1M
	清辉?中册		chillblade_qinghui_2		L150	2.4M
	清辉?下册		chillblade_qinghui_3		L150	6.4M
*/
	level = me->query("annie/chillblade_qinghui");
	if( !userp(me) ) {
		level = 5;
	}
	weapon = me->query_temp("weapon");
	extra = target->query_busy();
	target->start_busy(1);
	msg = HIW"\n是时间，一轮冰镜正盈于天心，似水的清辉遍洒大地，枝上繁花在
月光下齐齐绽放，空气里漂浮着一层若有若无的淡淡幽香。

"HIG"在凄美的月色中，$N"HIG"轻轻的扬起"+(me->query_weapon())->name()+HIG"，顺着月光的流动向还在异景
中怔忡的$n"HIG"一刀斩下。\n"NOR;

	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	extra?target->start_busy(extra):target->stop_busy();
	if( target->query_temp("damaged_during_attack") && me->query("mana") ) {
		// 150v spells + 200lv heart-listening = 150*6 + 200*2 = 1300 max mana
		// 1300 * 2 = 2600 damage.
		// ability + 500 --> 3600 damage
		if( level >= 1 ) {
			extra = 1;
		}
		if( level >= 2 ) {
			extra = 3;
		}
		bonus = me->query("mana")*(extra+1)/4;
		bonus = COMBAT_D->magic_modifier(me, target,"kee", bonus);
		bonus = bonus*(100+F_ABILITY->check_ability(me,"3_myqh_add",3)*2)/100;
		if( userp(me) ) {
			me->set("mana", 0);
		}
		message_vision(WHT"\n月下清辉有似寒烟，又如笼雾，浅浅地渗进$N"NOR+WHT"薄薄的伤口之中．．．\n"NOR, target);
		target->receive_damage("kee", bonus, me);
	//	target->receive_wound("kee", bonus, me);
		COMBAT_D->report_status(target);
		if( level >= 3 ) {
			target->perform_busy(target->query_busy()+1); // +1 busy,cant cancel.
		}
	} else {
		if( userp(me) ) {
			me->add("mana", -250);
		}
		// so maximum you can attempt 3600/3350/3100/2850/2600。。。。。。
		// at lower level it's 2000/1750/1500/1250/1000 5 times, but low level easier to hit due to full chillblade early.
	}
	me->force_status_msg("all");
	COMBAT_D->win_lose_check(me, target, bonus);
	me->perform_busy(2);
	return 1;
}