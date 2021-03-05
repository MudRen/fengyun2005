// silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int bonus, skill_lv, extra;
	int no_dodge, no_parry, exp_bonus;
	
	if( userp(me) ) {
		if( me->query("class") != "lama" ) {
			return notify_fail("『印契』是大昭寺的独门密技。\n");
		}
	}
	bonus = me->query_skill("lamaism", 1);
	if( bonus < 100 ) {
		return notify_fail("『印契』需要100级密宗佛法。\n");	
	}
	skill_lv = me->query_skill("bloodystrike", 1);
	if( skill_lv < 100 ) {
		return notify_fail("『印契』需要100级密宗大手印。\n");	
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『印契』只能对战斗中的对手使用。\n");
	}
	me->add_temp("apply/attack", skill_lv);
	me->add_temp("apply/damage", skill_lv);
	target->set_temp("no_check_pfm_win", 1);

	msg = HIG "$N"HIG"微微一笑，双手合拢，食指压中指，姆指压小指，无名指背立，似含苞待
放的莲花往$n"HIG"推去，正是禅功起手式『实住大手印』。" NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	if( objectp(target) && target->query_temp("damaged_during_attack") ) { 	
		target->add_temp("cant_dodge", 1);
		message_vision(WHT"·$N身子一晃，步法迟钝，难以闪避·\n"NOR,target);
		no_dodge = 1;
	}

	msg = YEL"$N"NOR+YEL"原印不动，但双手一翻，本是往外推的一印化做上举，顿时气劲突然改变，
如莲花怒放，威势无两，却是第二式『空乐大手印』。" NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	if( objectp(target) && target->query_temp("damaged_during_attack") ) { 	
		target->add_temp("cant_parry", 1);
		message_vision(WHT"·$N身子一晃，两臂酸麻，无力招架·\n"NOR, target);
		no_parry = 1;
	}

	me->add_temp("apply/attack", -skill_lv);
	me->add_temp("apply/damage", -skill_lv);

	extra = bonus/2 + skill_lv;
	msg = HIR"$N"HIR"双掌随即合拢抱拳，只余姆指及食指突出呈内弓状，右手掌心透背而红，
口中正宣佛号，一掌击出第三式『光明大手印』！" NOR;
	exp_bonus = (me->query("combat_exp")-3000000)/1000*extra/6000;
	if( exp_bonus < 0 ) {
		exp_bonus = 0;
	}
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra+exp_bonus);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra-exp_bonus);

	if( objectp(target) ) {
		if( no_parry ) {	
			target->add_temp("cant_parry", -1);
		}
		if( no_dodge ) {
			target->add_temp("cant_dodge",-1);			
		}
	}
	
	if( objectp(target) ) {
		if( target->query_temp("damaged_during_attack") ) { 
			COMBAT_D->win_lose_check(me, target, 1);
		}
	}
	
	if( objectp(target) ) {
		target->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

	me->perform_busy(3);
	return 1;
}
