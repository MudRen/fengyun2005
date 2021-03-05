// 『化霜诀』〔remedy〕：Heal over time
//  L150: 200 内力，amount = skill 运行十次every 8 sec，max; 300*10 = 3000


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount1)
{
	int level,i, skill, amount, ability;
	object *enemy, *mem;

	if( me->query("class") != "huashan" ) {
		return notify_fail("只有华山弟子才能用此心法！\n");
	}
	level = me->query_skill("hanmei-force",1);
	if( level < 150 ) {
		return notify_fail("需要150级的寒梅心法。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
		}
	}
	if( userp(me) && !COMBAT_D->legitimate_heal(me,target) ) {
		return notify_fail("你不能向此人使用此疗伤心诀。\n");
	}
	if( target->query_temp("pfm/hanmei_remedy") ) {
		return notify_fail("此人已经在恢复中了。\n");
	}
	if( me->query_skill("hanmei-force",1) >= 200 ) {
		skill = 300;
	} else if( me->query_skill("hanmei-force",1) >= 170) {
		skill = 250;
	} else {
		skill = 200;
	}
	if( me->query("force") < skill ) {
		return notify_fail("需要"+skill+"点的内力。\n");
	}
	if( target != me ) {
		message_vision(HIG "$N"HIG"运起化霜心法，食指拇指捏个诀儿，真力源源不断输入$n"HIG"体内。\n\n"NOR,me,target);
	} else {
		message_vision(HIG "$N"HIG"运起化霜诀，食指拇指捏个诀儿，真力源源不断地在体内循环。\n\n"NOR,me);
	}
	if( userp(me) ) {
		if( F_ABILITY->check_ability(me,"heal_add") > random(100) ) {
			tell_object(me,YEL"（你内息贯通，举重若轻地使出了这一招）\n"NOR);
		} else {
			me->add("force", -skill);
		}
	}
	if( target->is_fighting() ) {
		enemy = target->query_enemy();
		for( i = 0; i < sizeof(enemy); i++ ) {
			if( !enemy[i]->is_fighting(me) ) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}
	}
	ability = F_ABILITY->check_ability(me, "huashang_add");
	amount = skill*(100+ability*3)/100;
	amount = COMBAT_D->magic_modifier(me, target, "kee",amount);
	target->set_temp("pfm/hanmei_remedy", 1);
	call_out("fillup", 8, target, 10, 0, amount);
	me->start_busy(1);
	return 1;
}

void fillup(object me, int total, int count, int amount)
{
	if( !me ) {
		return;
	}
	if( me->query_temp("pfm/hanmei_remedy") < 1 ) {
		me->delete_temp("pfm/hanmei_remedy");
		return;
	}
	if( ++count > total ) {
		tell_object(me,YEL"在你周身流转的那股真气渐渐消失了。\n"NOR);
		me->delete_temp("pfm/hanmei_remedy");
		return;
	} else {
		// only heals when necessary, otherwise it's unnecessary hate.
		if( me->query("kee") < me->query("max_kee") ) {
			me->receive_fulling("kee", amount, me);
		}
		tell_object(me,WHT"真气震荡，顺着你奇经八脉迅疾流动，伤口慢慢愈合。\n"NOR);
		call_out("fillup", 8, me, total, count, amount);
	}
	return ;
}