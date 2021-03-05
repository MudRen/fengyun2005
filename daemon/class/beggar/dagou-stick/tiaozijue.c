//modified pfm msg by still
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, lvl, enhance;
	int skill, myexp, yourexp, count, i;
	int gwxd_dmg;
	object weapon, hisweapon;
	mapping buff;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("『挑字诀』只传授给丐帮弟子！\n");
	}
	lvl = (int) me->query_skill("dagou-stick", 1);
	if( lvl < 100 ) {
		return notify_fail("『挑字诀』需要100级的打狗棒法！\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" ) {
		return notify_fail("『挑字诀』需要混沌心法的配合。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『挑字诀』只能对战斗中的对手使用。\n");
	}
	weapon = me->query_temp("weapon");
	hisweapon=target->query_temp("weapon");
	if( !hisweapon ) {
		if( target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
			target->delete_temp("annie/beggar/time");
			message_vision(CYN"$N悄悄走到$n背后，飞身纵起，猛然向$n扑去！" NOR, me, target);
			skill = me->query_skill("betting",1);
			myexp = me->query("combat_exp");
			yourexp = target->query("combat_exp");
			count = me->query_agi()/10;
			i = 0;
			if( myexp/2 + random(myexp*4) <  yourexp ) {
				message_vision(YEL"$N不知何时却已转到了$n的身后，$n扑了个空。\n"NOR,target,me);
			} else {
				while( count-- ) {
					if( me ->is_busy() ) {
						continue;
					}
					msg = BLU"阴影中飞出第"+chinese_number(i+1)+"招\n"NOR;
					me->add_temp("apply/damage", lvl);
					COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
					me->add_temp("apply/damage", -lvl);
					i++;
				}
			}
			me->perform_busy(1);
			return 1;
		} else {
			return notify_fail("对方没有武器，无从使用『挑字诀』。\n");
		}
	}
	if( hisweapon->query("nodrop_weapon") ) {
		if (target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
			target->delete_temp("annie/beggar/time");
			message_vision(CYN"$N悄悄走到$n背后，飞身纵起，猛然向$n扑去！"NOR, me, target);
			skill = me->query_skill("betting", 1);
			myexp = me->query("combat_exp");
			yourexp = target->query("combat_exp");
			count = me->query_agi()/10;
			i = 0;
			if( myexp/2 + random(myexp*4) <  yourexp ) {
				message_vision(YEL"$N不知何时却已转到了$n的身后，$n扑了个空。\n"NOR, target, me);
			} else {
				while( count-- ) { 
					if( me->is_busy() ) {
						continue;
					}
					msg = BLU"阴影中飞出第"+chinese_number(i+1)+"招\n"NOR;
					me->add_temp("apply/damage", lvl);
					COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
					me->add_temp("apply/damage", -lvl);
					i++;
				}
			}
			me->perform_busy(1);
			return 1;
		} else {
			return notify_fail("这件武器看来没法挑下来。\n");
		}
	}
	enhance = 150;
	if( target->query_temp("annie/beggar/6") == "tiao" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		enhance *= 2;  // +100%
		target->delete_temp("annie/beggar/time");
	}
	if( target->query_temp("marks/disarmed")+60 > time() && enhance == 150 ) {
		// slll后的挑字诀不受60sec影响
		return notify_fail("对方现在防备的很严，没希望挑下来。\n");
	}
	mod = COMBAT_D->can_busy(me, target, "dagou-stick");
	if( !mod ) {
		mod = 1000;
	}
	if( me->query("force") < 100 ) {
		return notify_fail("你的内力不够。\n");
	}
	if( userp(me) ) {
		me->add("force", -50);
	}
	target->set_temp("marks/disarmed", time());
	msg = YEL"\n$N捏个棒诀将手中"+weapon->name()+YEL"一转，轻喝一声“起！”，使出「挑字诀」，搭住"
			+hisweapon->name()+YEL"向上挑出。\n\n"NOR;
	message_vision(msg, me, target);
	if( COMBAT_D->do_busy_attack(me, target, "dagou-stick/taiozijue", "step", enhance, mod) ) {
		msg = HIG"$n只感"+hisweapon->name()+HIG"似欲脱手飞出，一个把握不住，手中"+hisweapon->name()+HIG"被挑飞了出去。\n"
				+HIG"$n眼望下落的"+hisweapon->name()+HIG"伸手欲接，却被$N"HIG"手中的"+weapon->name()+HIG"又一番疾攻，\n"
				+HIG"只好任"+hisweapon->name()+HIG"落在一边。\n"NOR;
		if( hisweapon->unequip() ) {
			buff =
			([
				"caster":me,
				"who":target,
				"type":"disarmed",
				"att":"curse",
				"name":"打狗棒法·挑字诀",
				"buff1":"disarmed",
				"buff1_c":1,
				"time":30,
				"buff_msg":" ",
			]);
			ANNIE_D->buffup(buff);
		}
	}  else {
		msg = WHT"$n"+WHT"力贯于腕，手中"+hisweapon->name()+WHT"往下一压，将"+weapon->name()
				+WHT"荡了开去。\n\n"NOR;
	}
	message_vision(msg, me, target); 
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 ) {
		if( random(100) < F_ABILITY->check_ability(me, "doggie_tail", 1)*2 + 20 ) {
			// 20% + 20%
			msg = YEL"$N"+YEL"舔舔嘴唇，只觉得意犹未尽，说道：再来一招！\n"NOR;
			message_vision(msg, me, target);
			gwxd_dmg = F_ABILITY->check_ability(me,"3_gwxd_add",3)*15;
			me->add_temp("apply/damage", gwxd_dmg);
			COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			me->add_temp("apply/damage", -gwxd_dmg);
		}
	}
	if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
		me->perform_busy(1);
	} else {
		me->perform_busy(2);
	}
	return 1;
}
