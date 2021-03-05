// Silencer@fengyun	June.2005
// 『血雨潇潇』：击中后的5个回合可降低对手的有效铁布衫，2-SB

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int basic_armor(object victim)
{
	int armor, eff_ness, absorb_vic;
	string absorb_skill;
	
	if( victim->query_skill("iron-cloth") ) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if( absorb_skill ) {
			if( !(eff_ness = SKILL_D(absorb_skill)->ic_effect()) ) {
				eff_ness = 100;	
			}
			absorb_vic = victim->query_skill("iron-cloth",1)/2
					+ victim->query_skill(absorb_skill) * eff_ness/200
					+ victim->query_temp("apply/iron-cloth");
		} else {
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1)/2
							+ victim->query_temp("apply/iron-cloth");
		}
	} else {
		absorb_vic = victim->query_temp("apply/iron-cloth");
	}
	return absorb_vic;
}

int perform(object me, object target)
{
	string forceskill, msg;
	int extra, exp_bonus;
	int tmp, rate;
	int time, chance;
	object weapon;
	mapping buff;
	
	if( me->query("class") != "fugui" ) {
		return notify_fail("『血雨潇潇』是富贵弟子的绝招。\n");
	}
	weapon = me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear", 1);
	tmp = me->query_skill("skyforce", 1);
    	    	
	if( tmp < 150 || extra < 160 ) {
		return notify_fail("『血雨潇潇』需要160级的血战枪法和150级碧空心法!\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『血雨潇潇』只能对战斗中的对手使用。\n");
	}
	if( ANNIE_D->check_buff(target, "ic-curse") ) {
		return notify_fail("敌人已经中了此招了。\n");
	}
	if( !target->query_skill("iron-cloth") ) {
		return notify_fail("对方没有硬功，用此招没有用啊。\n");
	}
	me->add_temp("apply/attack", 100+extra);
	me->add_temp("apply/damage", tmp);
	msg = RED"\n$N"RED"手中"+weapon->name()+NOR+RED"枪花大盛，宛似电殛，直击$n"NOR+RED"气门，$n"NOR+RED"大惊疾退，
但枪劲不但未减，反而更疾！如血雨潇潇，急扑$n！\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM,"");
	me->add_temp("apply/attack", -100-extra);
	me->add_temp("apply/damage", -tmp);
        
	if( target->query_temp("damaged_during_attack") && !ANNIE_D->check_buff(target, "ic-curse") && target->query_skill("iron-cloth") ) {	
		rate = target->query_skill("iron-cloth");
		extra = (extra > 200) ? 200 : extra;
		rate = basic_armor(target);
		rate = rate * (extra + 150)/1000;
		if( wizardp(me) ) {
			write ("deduction is " + rate + "\n");
		}
		chance = F_ABILITY->check_ability(me, "3_xyxx_add", 3) * 10;
		if( random(100) < chance ) {
			time = 16;
		} else {
			time = 8;
		}
		buff =
		([
			"caster": me,
			"who": target,
			"type": "ic-curse",
			"att": "curse",
			"name": "血战枪法·血雨潇潇",
			"buff1": "apply/iron-cloth",
			"buff1_c": -rate,
			"time": 8,
			"buff_msg": WHT"$N浑身一震，真气急泄，一身硬功如兵败甲。\n" NOR,
			"special_func": 0,
		]);
		ANNIE_D->buffup(buff);
		tell_object(me, WHT"血战枪法·血雨潇潇的持续时间（"+(int)time+"秒）。\n"NOR);
	}
        
	me->perform_busy(1); 
	return 1;
}


