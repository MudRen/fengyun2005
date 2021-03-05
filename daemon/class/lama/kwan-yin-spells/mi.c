//About conditions types : （see condition.h 定义）高序列的解毒包括低序列。
//NO_CURE				- 不能医治的Conditions，一般是用在特定的场合。
//SPECIFIC_POISON		- 高级毒 -- 此类毒无普遍解法，唯有对症的药物方行。
//MID_POISON			- 中级毒 -- 特定门派的解毒心法，或是名贵药物。 
//LOW_POISON			- 低级毒 -- 一般可以学到的心法，或是普通药物。
//GENERIC				- 伤风咳嗽，醉酒花柳类。
//	--- Silencer@fy4  in 12/21/2002

inherit "/daemon/condition/generic_condition";
inherit SSERVER;

#include <ansi.h>
#include <condition.h>


int cast(object me, object target)
{
	int extra;
	object *mem;

	if( me->query("class")!="lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用观音六字明咒。\n");
	}
	extra = me->query_skill("kwan-yin-spells", 1);
	if( extra < 70 ) { 
		return notify_fail("『咪』需要70级的观音六字明咒。\n");
	}
	if( (int)me->query("mana") < 100 ) {
		return notify_fail("『咪』需要100点的法力。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target == me ) {
		message_vision(HIC "$N面呈无限虔诚憧憬之色。双手合十祈愿，低声念道：『咪』\n\n"NOR
+HIM"一轮神圣的光彩笼罩在$N周围，法力源源不绝流转。\n\n"NOR,me,target);
	} else {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target, mem) == -1 ) {
			return notify_fail("你只能给同一队伍中的人驱毒。\n");
		}
		message_vision(HIC "$N面呈无限虔诚憧憬之色。双手合十祈愿，低声对$n念道：『咪』 \n\n"NOR
	HIM"一轮神圣的光彩笼罩在$N周围，$N面现普度众生的慈悲之色，法力源源
不绝流入$n体内。$n感到体内生机勃勃，而$N的面色却渐渐枯萎。\n\n"NOR, me, target);
	}

	if( userp(me) ) {
		me->add("mana",-100);
	}
	if( extra < 200 ) {
 		target->clear_condition_type(LOW_POISON);
	} else {
 		target->clear_condition_type(MID_POISON);
	}
	return 1;
}
