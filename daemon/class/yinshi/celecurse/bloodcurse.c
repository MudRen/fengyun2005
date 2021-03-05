// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg, id_enemy, dot_owner, dir, index;
	int damage, ap, skill, ability, busy, super;
	int total;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("只有帝王谷弟子才能下『血降』\n");
	}
	skill = me->query_skill("celecurse", 1);
	if( skill < 120 && userp(me) ) {
		return notify_fail("『血降』需要120级通天降！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("这种降头术只能对战斗中的对手使用。\n");
	}
	if( me->query("kee") < 5 && userp(me) ) {
		return notify_fail("『血降『至少需要自身气血5点。\n");
	}
	me->receive_wound("kee", 5);
	msg = HIR"\n$N" HIR"在空中大旋身，一团血雾喷出，项上的人头竟然断开，向$n飞撞而来！"NOR;
	me->add_temp("apply/cursism", skill*2);

	if( COMBAT_D->do_magic_attack(me, target, "cursism", "kee") ) {
		msg += WHT"
$n不知接好，还是不接好，只有用手一格。这一格之下，忽觉五指一震，
好像同时有五只冰冷的蚯蚓，一齐自五指指尖潜人血脉之中！\n\n"NOR;
		message_vision(msg, me, target);
		// 1500 damage, SB 3
		// 分为 initial + 3 DOT, 375*4 each
		damage = me->query_skill("cursism");
		damage = damage*3/4;
		ability = F_ABILITY->check_ability(me,"blood_add")*3;
		damage = damage * (100 + ability)/100;
		damage = COMBAT_D->magic_modifier(me, target, "gin", damage);
		target->receive_damage("gin", damage, me);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me, target, damage);

		if( random(100) < F_ABILITY->check_ability(me,"3_bcurse_add",3)*10 ) {
			total = 6;
		}else {
			total = 3;
		}
		dot_owner = file_name(me);
		sscanf(dot_owner,"%s#%s", dir, index);
		dot_owner = me->query("id")+ index;
		if( !target->query_temp("dot/celecurse/bloodcurse/"+dot_owner) ) {
			tell_object(target, BLU"一道黑线顺着你的手臂向上延伸。\n"NOR);
			target->set_temp("dot/celecurse/bloodcurse/"+dot_owner,1);
			call_out("dot", 8, me, target, total, 0, damage, dot_owner);
		} else {
			message_vision("no dot\n", me);
		}
	} else {
		msg += YEL"\n$n"YEL"看破$N血降的幻象，闪在一旁！！\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/cursism", -skill*2);
	busy = 2;
	super = me->query_skill("flying-dragon",1);
	if( super >= 100 ) {
		super = (super-100)/10;
		if( random(100) < super && me->query_temp("yl9x_times") < 2 ) {
			me->add_temp("yl9x_times",1);
			message_vision(WHT"$N一口真气吐出，身法竟然丝毫不显迟滞。\n"NOR, me);
			busy = 0;
		} else {
			me->set_temp("yl9x_times",0);
		}
	}
	me->perform_busy(busy);
	return 1;
}

void dot(object me, object enemy, int total, int count, int damage, string dot_owner)
{
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			tell_object(enemy, YEL"你中的血降终于消失了。\n"NOR);
			enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		}
		return;
	}
	message_vision(WHT"$N的手臂透过一丝寒气，又麻又痒。\n"NOR,enemy);
	enemy->receive_damage("gin",damage, me);
	COMBAT_D->report_status(enemy);
	COMBAT_D->win_lose_check(me,enemy,damage);
	count = count+1;
	if( count < total ) {
		call_out("dot", 8, me, enemy, total, count, damage, dot_owner);
	} else {
		message_vision(YEL"$N臂上的肤色由青转黄。又由黄转白，终于恢复了原状。\n"NOR,enemy);
//		enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		enemy->delete_temp("dot/celecurse/bloodcurse/"+dot_owner);
		return;
	}
	return ;
}
