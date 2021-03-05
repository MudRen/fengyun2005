// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *team, *team1;
	int i, skill, enhance, num, amount, duration;
	string msg;

	if( me->query("class") != "knight" ) {
		return notify_fail("只有快活林弟子才能够使用『悲酥散』\n");
	}
	skill = me->query_skill("dream-herb", 1);
	if( skill <120 ) {
		return notify_fail("『悲酥散』需要120级的云梦五花锦。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『悲酥散』只能对战斗中的对手使用。\n");
	}
	duration = me->query("timer/pfm/khl_beisusan") - time() + 20;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(duration)+"秒钟左右才能再次使用『悲酥散』\n");
	}
	enhance = 300;
	me->set("timer/pfm/khl_beisusan", time());
	// + 400 force for everyone, +350 for self. ... but need hit enemy.
	amount = skill*2*(100+F_ABILITY->check_ability(me, "3_beisusan_add", 3)*5)/100;
	message_vision(BBLU + HIM "\n$N招式忽然变慢，不可思议的慢，每出一招，便有淡香阵阵。。\n"NOR, me);
	if( COMBAT_D->do_magic_attack(me, target, "herb", "kee", enhance) ) {
		message_vision(HIR"$N满脸通红，跌跌撞撞，倒似是喝醉了酒一般。\n"NOR, target);
		tell_object(me,WHT"你觉得掌中越来越热，似乎有一股暖流注入。\n"NOR, target);
		if( userp(target) ) {
			if( target->query("force") >= amount ) {
				target->add("force", -amount);
			} else {
				target->set("force",0);
			}
			target->force_status_msg("force");
		}
		call_out("take_effect", 2, me, amount);
	} else {
		message_vision(YEL"$N屏息凝神，不为所动。\n"NOR, target);
	}
	me->perform_busy(2);
	return 1;
}

int take_effect(object me, int amount)
{
	object *team1, *team;
	int i, num;
	
	if( !me || me->is_ghost() ) {
		return 1;
	}
	team1 = me->query_team();
	if( !team1 ) {
		if( me->query("force") + amount < me->query("max_force")*2 ) {
			me->add("force", amount);
		} else {
			me->set("force", me->query("max_force")*2);
		}
		tell_object(me, WHT"暖气在经脉中巡行一周，汇入膻中穴。\n"NOR);
		me->force_status_msg("force");
	}else {
		team = filter_array(team1, (: present($1,environment($2)) :), me);
		num = sizeof(team);
		for( i = 0; i < num; i++ ) {
			if( !COMBAT_D->legitimate_buff(me, team[i]) ) {
				continue;
			}
			if( team[i]->query("force") + amount < team[i]->query("max_force")*2 ) {
				team[i]->add("force", amount);
			} else {
				team[i]->set("force", team[i]->query("max_force")*2);
			}
			tell_object(team[i],WHT"一股淡淡的暖气在你经脉中巡行一周，汇入膻中穴。\n"NOR);
			team[i]->force_status_msg("force");
		}
	}
	return 1;
}