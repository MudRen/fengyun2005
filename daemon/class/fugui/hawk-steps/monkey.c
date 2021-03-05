#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,extra,level,duration;
	mapping buff;
	int g,k,s,n;
	function f;

	if (me->query("class") != "fugui")
		return notify_fail("只有富贵弟子才能施展『寒凛罗血』。\n");

	extra = me->query_skill("skyforce",1);
	if (extra < 160 && userp(me))
		return notify_fail("『寒凛罗血』需要至少160级的碧空心法。\n");

	extra = me->query_skill("hawk-steps",1);
	if (extra < 160 && userp(me))
		return notify_fail("『寒凛罗血』需要至少160级的鲲鹏步法。\n");

	duration = me->query("timer/pfm/fg-monkey") + 30 -time();
	if (duration > 0)
       	return notify_fail("『寒凛罗血』需要等待"+duration+"秒后才能再次施展。\n");

	if (ANNIE_D->check_buff(me,"fg-monkey")>0){
		ANNIE_D->debuff(me,"fg-monkey");
		return 1;
	}
	
	me->set("timer/pfm/fg-monkey", time());
		
	target = me;
	
	n = 2;
	
	g = target->query("max_gin") / n;
	k = target->query("max_kee") / n;
	s = target->query("max_sen") / n;

	f = (: call_other, __FILE__, "fullnpc",target,g,k,s :);

	me->full_me();
	buff =
		([
			"caster":me,
			"who":target,
			"type":"fg-monkey",
			"att":"bless",
			"name":"冷雪心经·寒凛罗血",
			"buff0": "apply/dodge",
			"buff0_c": 200,
			"buff1":"gin",
			"buff1_c":-g,
			"buff2":"kee",
			"buff2_c":-k,
			"buff3":"sen",
			"buff3_c":-s,
			"time":10,
			"buff_msg":HIW"$N"HIW"浑身剧颤，如堕冰窟，只觉得心跳骤止，血液几近凝结！\n\n"NOR,
			"disa_msg":WHT"$N"WHT"的血脉渐通，慢慢喘过气来。\n"NOR,
			"finish_function":bind(f, this_object()),
			"disa_type":3,
			"special_func":1,
		]);
	ANNIE_D->buffup(buff);
    return 1;
}


void fullnpc(object target,int g,int k,int s)
{
	if (!target)	return;
	target->add("eff_gin",g);
	target->add("eff_kee",k);
	target->add("eff_sen",s);
	return;
}

