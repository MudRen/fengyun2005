//博浪一击// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
#include <combat.h>

int tobe(object me,object target,object weapon, object room);
int disrupted (object me, object who, string how);

int perform(object me, object target)
{
	string msg;
	int extra, i;
	object weapon;
	int duration;
	function f = (: disrupted :);

	extra = me->query_skill("assassin-hammer",1);
	if( me->query("class") != "wolfmount" ) {
		return notify_fail("只有狼山弟子才能使用『博浪一击』\n");
	}
	if( extra < 140 ) {
		return notify_fail("『博浪一击』需要140级的博浪锤法。\n");
	}
	if( me->query_skill_mapped("force") != "wolf-force") {
		return notify_fail("搏浪锤法需要天狼心法为基础。\n");
	}
	if( !target || !target->is_character() ) {
		return notify_fail(HIR"你要暗算谁？\n"NOR);
	}
	if( target == me ) {
		return notify_fail(HIR"你不想活了？\n"NOR);
	}
	if( target->query_max_hate() == me ) {
		return notify_fail("只有在对手对你疏于防范时才能使用此招。\n");
	}
	if( !target->is_fighting(me) ) {
		return notify_fail("战斗外的刺杀请使用『荆轲刺秦』\n");
	}
	if( userp(me) ) {
		if( !COMBAT_D->legitimate_kill(me, target) ) {
			if( stringp(target->query("NO_KILL")) ) {
				return notify_fail(target->query("NO_KILL"));
			}
			if( stringp(target->query("NO_PK")) ) {
				return notify_fail(target->query("NO_PK"));
			} else { 
				return notify_fail("你无法攻击此人。\n");
			}
		}
	}

	// This won't affect single ppl much, it just prevent 2 wolves ping-pang
	duration = target->query_temp("marks/just_assed") + 6 - time();
	if( duration > 0 ) {
		return notify_fail("此人已经是其他人飞锤的目标了或者刚中了飞锤，等上几秒钟吧。\n");
	}
	target->set_temp("marks/just_assed", time());
	weapon = me->query_temp("weapon");
	me->delete_temp("last_damage_from");
	me->set_temp("marks/pfm/bolangyiji", time());
	tell_object(me, HBBLU HIC"\n你趁其不备，飞速转到" + target->query("name") + HBBLU HIC"身后，『博浪一击』蓄势待发！\n"NOR);
	me->start_busy(4, f);
	call_out("tobe", 6, me, target, weapon, environment(me));
	return 1;
}


int disrupted(object me, object who, string how)
{
	if( how == "hit" ) {
		if( F_ABILITY->check_ability(me, "3_blyj_add", 3)*2 > random(100) ) {
			tell_object(me, WHT"你静气凝神，不为所动，硬受一击！\n"NOR);
			me->set_temp("marks/blyj_pass",1);
		}
		tell_object(me,WHT"糟了，被发现了，你不得不放弃了博浪一击的企图！\n"NOR);
		me->delete_temp("marks/pfm/bolangyiji");
		me->delete_temp("marks/blyj_pass");
		return 1;
	}
	return 0;
}


int tobe(object me,object target,object weapon, object room)
{
	string msg;
	int pass, hit_damage, damage, stage, rate, crit;

	if( !me ) {
		return 1;
	}
	if( me->query_temp("marks/blyj_pass") ) {
		pass = 1;
	} else {
		pass = 0;
	}
	me->delete_temp("marks/blyj_pass");
	if( !me->query_temp("marks/pfm/bolangyiji") ) {
		return 1;
	}
	if( me->query_temp("marks/pfm/bolangyiji") + 5 > time() ) {
		return 1; // 这是上一个被打中但是没取消的.
	}
	if(!target || environment(target) != environment(me) || !target->is_fighting(me) || room != environment(me) ) {
		tell_object(me, WHT"真可惜，你要刺杀的目标溜走了。\n"NOR);
		return 1;
	}
	if( !pass ) {
		if( me->query_temp("last_damage_from") || me->query_temp("is_unconcious") ) {
			return 1;
		}
		if( target->query_max_hate() == me ) {
			tell_object(me, WHT"糟了，被发现了，你不得不放弃了博浪一击的企图！\n"NOR);
			return 1;
		}
	}
	if( !present(weapon, me) || weapon->query("equipped") != "wielded" ) {
		tell_object(me, WHT"手软了？你怎么把武器收起来了？ \n"NOR);
		return 1;
	}
	me->stop_busy();
	msg = YEL "\n$N跃身而起，手中"+weapon->query("name")+YEL"一转，带起阵阵风雷之声。\n$N手一抖，" + weapon->query("name") + YEL"脱手飞出，如风卷黄沙呼啸着击向$n。 \n"NOR;
	message_vision(msg, me, target);
	weapon->move(environment(me));
	rate = 80;
	stage = F_LEVEL->get_level(me->query("combat_exp"));
	if( stage >= 105 ) {
		// 6.6 M
		rate = 100;
	} else if( stage >= 95 ) {
		// 5.6 M
		rate = 90;
	}
	// write ("rate is " + rate + "\n");	
	// 150*3 + 100 = 550, 485*3 + 100 = 1555
	// Players can reach skill cap @4.6M, so we use hard code to limit it
	// @4.6M 左右, 1088*1.5 = 1632
	// 1321* 1.5 = 1982 dmg @ 5.6M+
	// 1555* 1.5 = 2332 dmg @ 6.6M + 
	hit_damage = 100 + me->query_skill("hammer")*3*rate/100;
	hit_damage = hit_damage * (F_ABILITY->check_ability(me,"bolang2_add")*2+100)/100;
	if( F_ABILITY->check_ability(me,"bolang1_add") > random(100) ) {
		hit_damage = hit_damage *2;
	}
	// inherently 2% critical chance
	if( F_ABILITY->check_ability(me,"bolang1_add")+2 > random(100) ) {
		hit_damage = hit_damage *2;
		crit = 1;
	}
	if( COMBAT_D->do_busy_attack(me, target, "assassin-hammer/bolangyiji", "unarmed", 500, 10) || ANNIE_D->check_buff(me,"assassinate") ) {
		damage = hit_damage + random(hit_damage);
		if( ANNIE_D->check_buff(me,"assassinate") ) {
			damage = hit_damage *2;
		}
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		if( damage >= hit_damage*3/2 ) {
			msg = HIR"只见" + weapon->query("name") + HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HIR"的头部！\n"NOR;
		} else {
			msg = HIR"只见" + weapon->query("name") + HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HIR"的胸口！\n"NOR;
		}
		if( crit ) {
			msg = HBRED+HIW"只见" + weapon->query("name") + HBRED+HIW"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HBRED+HIW"的眉心！\n"NOR;	
		}
		message_vision(msg, me, target);
		target->receive_damage("kee", damage, me);
		target->set("eff_kee",target->query("kee"));
		COMBAT_D->report_status(target);
	} else {
		msg = HIR"只见" + weapon->query("name") + HIR"带着一阵劲风贴着$n"HIR"的脑袋飞过，只差几寸没有击中！\n"NOR;
		message_vision(msg, me, target);
	}
	return 1;
}