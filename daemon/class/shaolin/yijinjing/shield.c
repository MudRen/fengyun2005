// Silencer @ FY4 workgroup. Aug.2004
//	1:1 -- 1:2 forceshield	2800 force == + 5600 kee

#include <ansi.h>

int exert(object me, object target)
{
	int extra, ratio, delay, factor;
	mapping buff;
	
	if( me->query("class") != "shaolin" ) {
		return notify_fail("只有少林高僧才能使用易筋经的『金光云拂』。\n");
	}
	extra = me->query_skill("yijinjing", 1);
	if( extra < 100 ) {
		return notify_fail("『金光云拂』需要100级的易筋经。\n");
	}
	if( userp(me) && F_LEVEL->get_level(me->query("combat_exp")) <= 55 ) {
		return notify_fail("恩，想自杀练功后免费使用特技？？？\n");
	}
	if( target && me != target ) {
		return notify_fail("『金光云拂』只能用在自己身上。\n");
	}
	if( ANNIE_D->check_buff(me, "forceshield") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	if( me->query("force") < 10 ) {
		return notify_fail("你至少需要花费10点内力。\n");
	}
	if( userp(me) ) {
		me->add("force",-10);
	}

	factor = (int)me->query_skill("force");
	if( me->query("scroll/yijinjing_shield") ==2 ) {
		ratio = 180*(10+factor/10)/20;
	} else if( me->query("scroll/yijinjing_shield") == 3 ) {
		ratio = 200*(10+factor/10)/20;
	} else {
		ratio = 150*(10+factor/10)/20;
	}

	message_vision(BGRN + WHT"$N深吸一口真气，内力澎湃而出。。。。。\n"NOR,me);
	buff =
		([
			"caster":me,
			"who":me,
			"type":"forceshield",
			"att":"bless",
			"name":"易筋经·金光云拂",
			"buff1":"till_death/shield_lock",
			"buff1_c":1,
			"time":300,
			"buff_msg":BGRN + WHT"气流扰动，似乎在$N周围结成一围气墙。\n"NOR,
			"disa_msg":YEL"你身上的气墙渐渐消失了。\n"NOR,
			"shield_desc":WHT"$N招式甫及$n身前三尺之外，便似遇上了一层柔软之极，却又坚硬之极的屏障。\n"NOR,
			"shield_amount":ratio,
			"shield_type":"force",
		]);
	ANNIE_D->buffup(buff);
	return 1;
}