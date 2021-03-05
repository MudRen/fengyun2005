// annie 07.2003
// dancing_faery@hotmail.com
// 冰镜刀法 
// 昆仑品雪·提高系数

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		int i,t,skill,level,damage;
		mapping buff;
		string msg;
		object weapon;

        skill = me->query_skill("chillblade",1);

		if (skill < 120)
        	return notify_fail("『昆仑品雪』需要至少120级的冰镜七诀。\n");

		if( ANNIE_D->check_buff(me,"skillup")) 
			return notify_fail("你现在正在施展类似的能力。\n");

		msg=HIR BLK"\n$N"HIR BLK"手中的刀突然慢了，慢得几近凝滞，"NOR WHT"像是高天之上流落的一片朦朦雪影，极缓，极慢，"HIW"却无处不在，无坚不摧。\n\n"NOR;

		buff =
		([
			"caster":me,
			"who":me,
			"type":"skillup",
			"att":"bless",
			"buff1":"annie/chillblade_skillup",
			"buff1_c":skill,
			"name":"冰镜七诀·昆仑品雪",
			"time":30,
			"buff_msg":msg,
		]);

		ANNIE_D->buffup(buff);

        return 1;
}



