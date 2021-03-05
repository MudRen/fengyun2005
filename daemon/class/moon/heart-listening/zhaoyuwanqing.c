// annie 07.2003
// dancing_faery@hotmail.com
// 朝雨晚晴
// 60秒内Dodge 3-15 hit，feat，cdt 30min
// 关于此pfm，需要在enable中判断，禁止效果间更换dodge。

// 从dodge中移动到cast.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
//int perform(object me, object target)
{
	string msg;
	int extra,	level, duration;
	mapping buff;
	
	if (me->query("class")!= "moon" && userp(me))
		return notify_fail("只有皓月宫人才能使用『朝雨晚晴』\n");
		
	if(me->query_skill("heart-listening",1) < 200 && userp(me))
		return notify_fail("『朝雨晚晴』需需要至少200级的幻念聆音。\n");

	extra = me->query_skill("stormdance",1);
	if (extra < 150)
		return notify_fail("『朝雨晚晴』需要至少150级的天岚凝舞。\n");

	level = me->query("annie/stormdance_zhaoyuwanqing");
	if (userp(me) && level<1)
		return notify_fail("『朝雨晚晴』需要得到有关卷轴后才能使用。\n");
		
	duration = me->query("timer/evade")+ 1800 -time();
	if( duration>0 && userp(me))	// 30min一次
       	return notify_fail(CYN"『朝雨晚晴』耗费体力极大，需等待"+duration/60+"分钟。\n"NOR);

	if (me->query("timer/evade") + 120 > time())
        	return notify_fail("『朝雨晚晴』耗费体力极大，不能连续使用。\n");

	if (me->query_skill_mapped("force") != "snowforce" && userp(me))
       	return notify_fail("『朝雨晚晴』需要以冷雪心经发动。\n");

	if (me->query_skill_mapped("dodge") != "stormdance" && userp(me))
       	return notify_fail("『朝雨晚晴』需要合天岚凝舞而用。\n");

	if( ANNIE_D->check_buff(me,"feat")) 
       	return notify_fail("你已经在施展某种类似的技艺了。\n");

	if (me->query("force") < 100 && userp(me))
		return notify_fail("『朝雨晚晴』需要消耗100点内力。\n");
	if (userp(me))
		me->add("force",-100);

/*朝雨晚晴?第一册	stormdance_zhaoyuwanqing_1		L150	1M	6
朝雨晚晴?第二册	stormdance_zhaoyuwanqing_2		L150	2.4M	9
朝雨晚晴?第三册 stormdance_zhaoyuwanqing_3		L150	4M		12
*/

	level = me->query("annie/stormdance_zhaoyuwanqing");
	if (me->query("class") != "moon")
		level = 0;
	if (!userp(me))
		level = 5;

	if (me->query("class") != "moon")
		level = 0;
	
	extra = 5 + (level-1) * 3;
	if (extra > 15)
		extra = 15;
	
	extra += 1;
	
	me->set("timer/evade",time());
	if (me->is_fighting() && userp(me))
	    me->perform_busy(1);

		buff =
			([
				"caster":me,
				"who":me,
				"type":"feat",
				"type2": "evade",
				"att":"bless",
				"name":"天岚凝舞·朝雨晚晴",
				"buffup_name":"evade",
				"buffup_type":""+extra,
				"buffup_ratio":extra,
				"time":60,
				"buff_msg":HIC"$N"HIC"屏息收神，施展聆音幻念，登时心境空灵，洞烛先机。\n"NOR,
				"disa_msg":WHT"\n你的心里渐渐有了杂念，不能再把握朝雨晚晴。\n\n"NOR,
				"special_func":2,
			]);
		ANNIE_D->buffup(buff);

        return 1;
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
