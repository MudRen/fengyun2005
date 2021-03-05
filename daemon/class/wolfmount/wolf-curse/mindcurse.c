// Geese/Silencer @fy4 workgroup

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	int skill, i, mod, duration;
	int time;
	object* inv;

	if( me->query("class") != "wolfmount" ) {
		return notify_fail("只有狼山弟子才能使用『摄心咒』\n");
	}
	skill = me->query_skill("wolf-curse", 1);	
	if( (skill < 200 || me->query_skill("cursism", 1) < 200) && userp(me) || me->query_skill("summonwolf", 1) < 260 ) {
		return notify_fail("『摄心咒』需要200级天狼血咒和降头术，260级唤狼术！\n");
	}
	// duration = 5mins.
	duration = me->query("timer/pfm/wm_mindcurse") + 300 - time();
	if( duration > 0 ) {
		return notify_fail("『摄心咒』极耗元神，需要"+duration+"秒钟后才能再次运用。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『摄心咒』只能对战斗中的对手使用。\n");
	}
	if( target->query_temp("mesmerize") || target->is_busy() ) {
		return notify_fail("对方已经在失魂落魄或忙乱中了，快抓紧时间进攻吧。\n");
	}
	mod = COMBAT_D->can_busy(me, target, "wolf-curse");	
	if( !mod ) {
		return notify_fail(HIW"此人功力深湛，不会被此咒法摄魂的。\n"NOR);
	}

	if( userp(target) ) {
		time = 10;
	} else {
		time = 10 + F_ABILITY->check_ability(me, "3_shexin_add", 3) * 2;
	}
	// Mesmerize timer, 无论成败都出现
	me->set("timer/pfm/wm_mindcurse", time());
	target->set_temp("busy_timer/wolf-curse", time());
	message_vision(HIB"\n$N突然发出沁人毛髓的啸叫，如同发狂的猛兽般欺身扑向$n！\n\n" NOR, me, target);

	// Quite high rate of success
	if( COMBAT_D->do_busy_attack(me, target, "wolf-curse/mindcurse", "step", 300, mod) ) {
		message("vision",HIR""+me->name()+HIR"的眼睛突然现出一片腥红之色，"+target->name()+HIR"的眼神与之一碰，当即呆立当场！\n"NOR, environment(me), ({target,me}));
		tell_object(me, HIR"你的眼睛突然现出一片腥红之色，"+target->name()+HIR"的眼睛与之一碰，当即呆立当场！\n"NOR);
		tell_object(target,
HIR""+me->name()+HIR"的眼瞳突然突然现出一片腥红之色，突然变成千百头狼从四面八方扑来，
你逃无可逃，避不可避，万念俱灰！\n"NOR);
		target->set_temp("mesmerize", time());
		target->start_call_out((: call_other, __FILE__, "remove_effect", target :), time*2);	
		target->start_busy(time);
		target->set_temp("condition_type", HIB" <失魂中> "NOR);
		me->remove_killer(target);
		me->add_rival(target);
		inv = all_inventory(environment(me));
		for( i = 0; i < sizeof(inv); i++) {
			// It can't stop teammate's pet
			if( inv[i]->query("possessed") == me || inv[i]->team_member(me) ) {
				if( inv[i]->is_fighting(target) ) {
					inv[i]->remove_killer(target);
					inv[i]->add_rival(target);		
				}
			}
		}			
		return 1;
	} else {	
		message_vision(HIC "$n见势不对，急忙后退，$N一扑落空，脚下不稳，向前冲出几步才站稳！\n" NOR, me, target);	
	}
	me->perform_busy(1) ;      	   	
	return 1;
}

void remove_effect(object target)
{
	object* enemy;
	int i;

	if( !target || !living(target) ) {
		return;
	}
	if( !target->query_temp("mesmerize") ) {
		return;
	}
	target->delete_temp("mesmerize");
	target->delete_temp("condition_type");
	tell_object(target, YEL"你终于回过神来。\n"NOR);
	enemy = target->query_enemy();
	for( i = 0; i < sizeof(enemy); i++) {
		if( objectp(enemy[i]) ) {
			enemy[i]->kill_ob(target);
			target->kill_ob(enemy[i]);
		}
	}
}


