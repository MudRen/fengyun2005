// annie 07.2003
// dancing_faery@hotmail.com
// 霜天雪舞
// HASTE 60 - 200，10 - 75。
// 关于此pfm，需要在enable中判断，禁止效果间更换dodge。

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra,level;
	
	if (me->query("class")!= "moon" && userp(me))
		return notify_fail("『霜天雪舞』为皓月宫特技。\n");
		
	extra = me->query_skill("stormdance",1);
	if (extra < 30)
		return notify_fail("『霜天雪舞』需要至少30级的天岚凝舞。\n");

	
	if( ANNIE_D->check_buff(me,"haste")) 
       	return notify_fail("你已经在施展类似的能力了。\n");

/*
霜天雪舞?上册	stormdance_shuangtianxuewu_1	L50		1M
霜天雪舞?中册	stormdance_shuangtianxuewu_2	L100	2.4M
霜天雪舞?下册	stormdance_shuangtianxuewu_3	L150	4M
*/
	level = me->query("annie/stormdance_shuangtianxuewu");
	if (me->query("class") != "moon")
		level = 0;
	if (!userp(me))
		level = 5;

	if (me->query("force") < 50)
		return notify_fail("『霜天雪舞』需要消耗50点内力。\n");
	if (userp(me))	me->add("force",-50);

	extra = 150 + level * 50;		// 150 - 200 - 250 - 300, 60%-75%

		buff =
			([
				"caster":me,
				"who":me,
				"type":  "haste",
				"att": "bless",
				"name": "天岚凝舞·霜天雪舞",
				"buff1": "apply/haste",
				"buff1_c":extra,
				"time":	  extra/5,
				"buff_msg":WHT"$N"NOR+WHT"脚踏虚幻，步走轻灵，身法如寒天飘雪，攻势渐紧。\n"NOR,
			]);
			
		ANNIE_D->buffup(buff);
        return 1;
}

