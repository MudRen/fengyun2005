// Silencer@fengyun	June.2005
// AE Attack, good for getting NPCs' attention when start fighting.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill, extra_attack, extra_damage, timer, duration, i, chance;
	object weapon;
	object* enemy;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("『旋风斩』为少林特技。\n");
	}
	skill = me->query_skill("wuche-axe",1);
	if( skill < 170 || me->query_skill("axe",1) < 170 ) {
		return notify_fail("『旋风斩』需要170级的悟彻波风斧法和170级的基本斧法！\n");
	}
	timer = 60 - F_ABILITY->check_ability(me,"xuanfeng_add")*2;	
	duration = me->query("timer/pfm/sl_xfz") + timer - time();
	if( duration > 0 ) {
    	return notify_fail("『旋风斩』需要"+chinese_number(duration)+"秒后才能再次使用。\n");
	}
	enemy = me->query_enemy();
	if( !sizeof(enemy) ) {
		return notify_fail("『旋风斩』只能对战斗中的对手使用。\n");
	}
	weapon = me->query_temp("weapon");
	msg = BBLU+HIY"$N"HIY"双手握斧，以左足作为中心，身子旋然而转，转动得出奇缓慢。
然后，突然间，斧风呼啸，不知怎地，竟已化做一片光幕，闪电般击出，
——这一斧是击向哪一个方位？谁也瞧不出。"NOR"

	"HIR"旋		风		斩"NOR+YEL"

	人影一闪——只是一闪，斧风、光影，便又奇迹般完全停顿。\n" NOR;

	message_vision(msg, me);
	msg = "";
	extra_attack = skill;
	extra_damage = skill * 3;

	me->add_temp("apply/attack", extra_attack);	
	me->add_temp("apply/damage", extra_damage);

	for( i = 0; i < sizeof(enemy); i++ ) {
		if( me->is_busy() ) {
			continue;
		}
		COMBAT_D->do_attack(me, enemy[i], TYPE_PERFORM, msg);
		if( enemy[i] ) {
			if( enemy[i]->query_temp("damaged_during_attack") ) {
				enemy[i]->add_hate(me, skill*6);
			}
		}
	}

	me->add_temp("apply/attack", -extra_attack);
	me->add_temp("apply/damage", -extra_damage);
	me->set("timer/pfm/sl_xfz", time());    
	me->perform_busy(1);
	return 1;
}
