#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void fullnpc(object target,int g,int k,int s);

int perform(object me, object target)
{
	int i,extra,level,duration;
	mapping buff;
	int g,k,s,n;
	function f;

	if (userp(me))
		return notify_fail("你所用的武功中没有这项特技。\n");
			
	if (me->query("class") != "moon")
		return notify_fail("只有皓月宫中人才能施展『寒凛罗血』。\n");

	extra = me->query_skill("snowforce",1);
	if (extra < 175 && userp(me))
		return notify_fail("『寒凛罗血』需要至少175级的冷雪心经。\n");

	extra = me->query_skill("stormdance",1);
	if (extra < 200 && userp(me))
		return notify_fail("『寒凛罗血』需要至少200级的天岚凝舞。\n");

/*寒凛罗血?册一	snowforce_hanlingluoxue_1	L175	1M
寒凛罗血?册二	snowforce_hanlingluoxue_2	L175	2.4M
寒凛罗血?册三	snowforce_hanlingluoxue_3	L175	4M
寒凛罗血?册四	snowforce_hanlingluoxue_4	L175	6.4M
*/

	level = me->query("annie/snowforce_hanlingluoxue");
	if (me->query("class") != "moon")
		level = 0;
	if (!userp(me))
		level = 5;

	if (level >= 2)
		i = 60;
	else
		i = 300;

	duration = me->query("timer/hanlingluoxue") + i -time();
	if (duration > 0)
       	return notify_fail("『寒凛罗血』需要等待"+duration+"秒后才能再次施展。\n");

	if( !target ) target = offensive_target(me);
	if( target == me) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『寒凛罗血』只能对战斗中的对手使用。\n");

	if (!userp(target) 
		&& (target->query("kee") * 3 < target->query("max_kee") 
			|| target->query("gin") * 3 < target->query("max_gin")
			 || target->query("sen") * 3 < target->query("max_sen")) 
			 && !target->query("test"))
	       	return notify_fail("此对象已经不需要施展『寒凛罗血』了。\n");	
	       	// 禁止用来争功夺利.... ^^ annie 07.2003

	i = ANNIE_D->check_buff(target,"gks");
	if (i>0)
	{
		buff = target->query_temp("buff/"+i);
		if (!mapp(buff) || buff["att"] == "curse")
	       	return notify_fail("此对象已经不需要施展『寒凛罗血』了。\n");
	}

	if (target->query("gender") != "女性")
		message_vision(HIW"\n$n"HIW"转折间骤然欺近$N"HIW"，双手变得莹白，十指微微分开，轻按在$N"HIW"胸前。\n",target,me);
	else
		message_vision(HIW"\n$n"HIW"转折间骤然贴到$N"HIW"身后，双手变得莹白，十指微微分开，拍击在$N"HIW"背心。\n",target,me);

	if (i)
		ANNIE_D->debuff(target,buff["type"]);

	if (level >= 4)
		n = 5;
	else if (level >= 1)
		n = 10;
	else 
		n = 20;

	g = target->query("max_gin") / n;
	k = target->query("max_kee") / n;
	s = target->query("max_sen") / n;

	if (level < 3)
	{
		g=0;
		s=0;
	}

	f = (: call_other, __FILE__, "fullnpc",target,g,k,s :);

	target->set_temp("last_damage_from",me);
	buff =
		([
			"caster":me,
			"who":target,
			"type":"gks",
			"att":"curse",
			"name":"冷雪心经·寒凛罗血",
			"buff1":"gin",
			"buff1_c":-g,
			"buff2":"kee",
			"buff2_c":-k,
			"buff3":"sen",
			"buff3_c":-s,
			"time":900,
			"buff_msg":HIW"$N"HIW"浑身剧颤，如堕冰窟，只觉得心跳骤止，血液几近凝结！\n\n"NOR,
			"disa_msg":WHT"$N"WHT"的血脉渐通，慢慢喘过气来。\n"NOR,
			"finish_function":bind(f, this_object()),
			"disa_type":3,
			"special_func":1,
		]);
	ANNIE_D->buffup(buff);
    me->perform_busy(2);
    return 1;
}


void fullnpc(object target,int g,int k,int s)
{
	if (userp(target))
		return;
	target->add("eff_gin",g);
	target->add("eff_kee",k);
	target->add("eff_sen",s);
	target->add("gin",g);
	target->add("kee",k);
	target->add("sen",s);
	return;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
