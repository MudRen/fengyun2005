// annie 07.2003
// dancing_faery@hotmail.com
// 冰镜刀法 
// 明月(perform mingyue.....*escape)
// 不失手的1HIT，用来结束战斗．．．

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus, level, duration;
	object weapon, *pros;

	extra = me->query_skill("chillblade",1);
	if( me->query("class") != "moon" && userp(me) ) {
		return notify_fail("只有皓月宫中人才能施展『明月』。\n");
	}
	if( me->query("gender") == "女性" && userp(me) ) {
		return notify_fail("女子不适合施展冰镜七诀的『明月』一式。\n");
	}
	if( extra < 190 && userp(me) ) {
		return notify_fail("『明月』需要至少190级的冰镜七诀。\n");
	}
	if( me->query("max_mana") < 1000 ) {
		return notify_fail("『明月』需要至少1000最大法力为基础。\n");
	}
	if( userp(me) && !me->query("annie/chillblade_mingyue") ) {
		return notify_fail("『明月』需要先从卷轴上悟出才能使用。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『明月』只能对战斗中的对手使用。\n");
	}
/*
明月?上册		chillblade_mingyue_1		L150	1M
明月?中册		chillblade_mingyue_2		L150	2.4M
明月?下册		chillblade_mingyue_3		L150	4M
*/
	level = me->query("annie/chillblade_mingyue");
	if( !userp(me) ) {
		level = 5;
	}
	if( userp(me) ) {
		if( level >= 3 ) {
			duration = me->query("timer/mingyue")+180-time();
			if( duration > 0 ) {
				return notify_fail("『明月』一式还须等待"+ duration+"秒钟。\n");
			}
		} else {
			duration = me->query("timer/mingyue")+240-time();
			if( duration > 0 ) {
				return notify_fail("『明月』一式还须等待"+ duration+"秒钟。\n");
			}
		}
	} else if( me->query("timer/mingyue") + 180 > time() ) {
		// 3min
		return notify_fail("『明月』一式三分钟之内只能使用一次。\n");
	}
	if( userp(me) && target->query_temp("annie/damaged_by_mingyue") ) {
		return notify_fail("此式用以杀人只得一次，一次失手，绝不再发。\n");
	}
	if( userp(me) && me->query("mana") < 1000 ) {
		return notify_fail("『明月』需要至少1000法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -1000);
	}
	me->set("timer/mingyue", time());

	if( extra >= 200 ) {
		// capped
		extra = 200;
	}
	extra += F_ABILITY->check_ability(me,"3_myqh_add",3)*2;
	bonus = extra/6*extra/6;
	me->add_temp("apply/damage", bonus); // 190: 1000dmg
	target->add_temp("cant_dodge",1);
	target->add_temp("cant_parry",1);
	pros = target->query_temp("protectors");
	target->delete_temp("protectors");
	me->add_temp("marks/full_hit_damage",1);
	msg = HIC"\n$N"HIC"乍然退步，旋身，反手，——拔刀。\n\n刀既出，天上的玉钩也失去了光华，地上的万物都屏息注视着$N"HIC"手中一弯明月。\n刀光如月，月光如刀。\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	message_vision(HIC"\n一弹指已是六十刹那，而刀锋切进又离开$N"HIC"的骨肉，只不过在一刹那间。\n刀光隐，明月现。\n"NOR,target);
	COMBAT_D->report_status(target); // snicker,假装是一个2hit的perform...
	me->add_temp("marks/full_hit_damage",-1);
	if( target ) {
		target->add_temp("cant_dodge",-1);
		target->add_temp("cant_parry",-1);
		target->set_temp("protectors",pros);
		target->set_temp("annie/damaged_by_mingyue",1);
	}
	me->add_temp("apply/damage",-bonus);
	if( level == 1 ) {
		me->perform_busy(2);
	}
	if( level == 2 ) {
		me->perform_busy(1);
	}
	return 1;
}



