// geese&silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, level, dam, n, count;
	object weapon;
	
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『龙现于野』只能对战斗中的对手使用。\n");
	}
	if( me->query_skill_mapped("force") != "lotusforce" ) {
		return notify_fail("白云杖法必须以莲华心法为基础。\n");
	}
	weapon = me->query_temp("weapon");
	level = me->query_skill("cloudstaff", 1);
	extra = level + F_ABILITY->check_ability(me,"3_lxyy_add",3)*3;
	
	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up")) {
		dam = level*3;
	} else {
		dam = level;		
	}
	if( level < 120 ) {
		me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage", dam);
		msg = HIY"$N低呼佛号，内力聚于双臂，手中的"NOR+weapon->name()+HIY"幻出一条金磷飞龙，\n闪电般的扑向$n！"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -dam);
		me->perform_busy(2);
		return 1;
	}
	if( level < 160 || me->query("class") != "bonze" ) {
		me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage",dam);
		msg = HIR"$N低呼佛号，内力聚于双臂，手中的"+weapon->name()+HIR"幻出无数条金磷飞龙，连续两招一气呵成，\n狂风暴雨般地攻向$n！\n\n第一式！龙现于野！"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		msg = HIB"第二式！龙翔于天！！"NOR;
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -dam);
		me->perform_busy(3);
		return 1;
	}
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage",dam);
	target->set_temp("no_check_pfm_win",1);
	msg = HIY"$N低呼佛号，内力聚于双臂，手中的"+weapon->name()+HIY"幻出无数条金磷飞龙，连续三招一气呵成，\n狂风暴雨般地攻向$n，正是白云杖法之精华所聚！\n"NOR;
	message_vision(msg, me, target);
	msg = HIY"『龙现于野』"HIB"$N"HIB"大喝一声，手中"+weapon->name()+HIB"虚虚实实，杖杖不离$n"HIB"的身边三寸。\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	msg = HIY"『龙翔于天』"HIC"漫天杖影中，"HIC"$N"HIC"突然轻身跃起，将手中"+weapon->name()+HIC"以千钧之力砸向$n。\n"NOR;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	msg = HIY"『龙腾四海』"HIR"$N"HIR"双脚乍一着地，双臂一震，惊涛般九杖连环攻出，同时攻到$n"HIR"九处要害。\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -dam);
	if( objectp(target) ) {
		if( target->query_temp("damaged_during_attack") ) {
			COMBAT_D->win_lose_check(me,target,1);
		}
	}
	if( objectp(target) ) {
		target->delete_temp("no_check_pfm_win");
		target->delete_temp("skip_damage_record");
	}
	me->perform_busy(3);
	return 1;
}