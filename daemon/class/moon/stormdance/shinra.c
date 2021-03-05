// annie 08.2004
// dancing_faery@hotmail.com
// 冰雪神罗

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, duration;
	
	if (userp(me))
		return notify_fail("你所用的武功中没有这项特技。\n");
		
	if (me->query("class") != "moon")
		return notify_fail("只有皓月宫的弟子才能施展『雾影神罗』。\n");

	extra = me->query_skill("stormdance",1);
	if (extra < 140)
		return notify_fail("『雾影神罗』需要至少140级的天岚凝舞。\n");

	duration = me->query("timer/pfm/shinra") + 1800 - time();
	if (duration > 0 && userp(me))
       	return notify_fail("你还需等待"+ duration/60+"分钟左右才能再次施出『雾影神罗』\n");

	if( ANNIE_D->check_buff(me,"feat")) 
       	return notify_fail("此特技和你已经在施展的一些特技冲突，不能同时使用。\n");

	buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"shinra",
			"att":"bless",
			"name":"天岚凝舞·雾影神罗",
			"time":90,
			"buff_msg":CYN"$N"NOR+CYN"心念灵犀，淡淡冷雾席裹而来，将其卷在云心。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/shinra",time());
	return 1;
}
