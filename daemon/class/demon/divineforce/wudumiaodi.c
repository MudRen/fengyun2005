// annie 6.27.03
// dealt sen damage depends on how many skills target learned

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	function f;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「无独妙谛」只能对战斗中的对手使用。\n");

    i = sizeof(target->query_skills());
	if (!i)
		return notify_fail("「无独妙谛」无法对对方使用。\n");

	if (ANNIE_D->check_buff(target,"chaosmind"))
		return notify_fail("对方已经心乱如麻，「无独妙谛」无需再用。\n");

	message_vision( YEL"\n$N欺近$n身前，附在$n耳边轻轻的吐出几句低语。\n"NOR,me,target);
	tell_object(target,BLU"你平生所学各艺忽然尽皆涌上心头混在一起，是是非非之间搅得你脑中一片混沌。\n"NOR);

	f = (: call_other, __FILE__, "fullnpc",target,i :);

	target->receive_damage("sen",i*i*2,me);

	buff =
			([
				"caster":me,
				"who":target,
				"type":"chaosmind",
				"att":"curse",
				"name":"破邪心经·无独妙谛",
				"time":120,
				"buff_msg":MAG"$N脸色骤变，瞪圆大眼，双手捂住左右太阳，似乎头痛欲裂！\n"NOR,
				"disa_msg":"你稳住大乱的心神，渐渐理清了思绪。\n",
				"finish_function":bind(f, this_object()),
			]);
	ANNIE_D->buffup(buff);
    COMBAT_D->report_status(target);
	return 1;
}


void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->add("sen",i*i*2);
	if (target->query("sen") > target->query("eff_sen"))
		target->set("sen",target->query("eff_sen"));
	target->status_msg("sen");
	return;
}

 
