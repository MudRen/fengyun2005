// void_sense.c by Silencer@fy4 workgroup
// -200 atk, -200 dodge for 50 sec

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	int skill, mod, amount;
	mapping buff;

	if( me->query("class") != "bonze" ) {
		return notify_fail("只有兴国禅寺的弟子才可以使用『空识神通』！\n");
	}
	if( me->query_skill("essencemagic", 1) < 60 ) {
		return notify_fail("『空识神通』需要60级八识神通！");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『空识神通』只能对战斗中的对手使用。\n");
	}
	if( ANNIE_D->check_buff(target, "powerdown") ) {
		return notify_fail("敌人已经中招了，还不抓紧时机攻击？\n");
	}
	if( me->query("atman") < 100 ) {
		return notify_fail("需要100点灵力！\n");
	}
	if( userp(me) ) {
		me->add("atman", -100);
	}
	message_vision(HIY "$N双手合十，垂眉俯首，低声吟诵。。。\n" NOR, me);
	skill= (int) me->query_skill("essencemagic",1);
	skill = skill > 200 ? 200: skill;
	skill = skill + F_ABILITY->check_ability(me,"3_void_add",3)*5;
	mod = COMBAT_D->can_busy(me, target, "essencemagic");
	if( !mod ) {
		mod = 10000;
	}
	amount = 30 + F_ABILITY->check_ability(me,"void_add");
	if( COMBAT_D->do_busy_attack( me, target, "essencemagic/void_sense", "unarmed", 400, mod) ) {
		buff =
		([
			"caster":me,
			"who":target,
			"type":"powerdown",
			"att":"curse",
			"name":"八识神通·空识",
			"buff1":"apply/dodge",
			"buff1_c":-skill,
			"buff2":"apply/attack",
			"buff2_c":-skill,
			"time": amount,
			"buff_msg":HIW"$N心头一颤，只觉繁华世事皆为过眼烟云，身形不由凝滞下来。\n"NOR,
			"disa_msg":RED"$N浑身一凛，恍若大梦初醒。\n" NOR,
			"disa_type":1,
		]);
		ANNIE_D->buffup(buff);
		return 1;
	}
	message_vision(HIR"$N大喝一声：“米粒之珠，也放光华？”\n"NOR, target);
	message_vision(YEL"$N面如土色，不自觉地微微颤动。\n"NOR, me);
	me->perform_busy(2);
	return 1;
}

