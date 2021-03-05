//	 increase damage potential *150%, but resistance-30%
// 	actually the duration here is detrimental in a degree
//	SS has burst damage zhuiming/yirancangyun on a long timer
//	short duration is better to reduce the penalty :D
 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
		string msg;
		int extra, duration, attack_bonus, damage;
		mapping buff;
	
		if (me->query_skill("nine-moon-sword",1) < 170)
			return notify_fail("『碧映光寒』需要170级九阴剑法。\n");
				
		duration = me->query("timer/pfm/ss_bygh") + 120 - time();
		if (duration>0)
			return notify_fail("你需要等待"+duration+"秒才能再次使用『碧映光寒』。\n");
					
		if (!me->is_fighting())
			return notify_fail("此特技只能在战斗中使用。\n");
			
		if (ANNIE_D->check_buff(me,"criticalup"))
	   	   	return notify_fail("你已经在运用类似的武功了。\n");

		msg = HIG "$N"HIG"望天，发眉衣履尽碧，拔剑，剑色更碧，剑光掠起，映亮脸上万物皆死的杀意。\n"NOR;	    	
		buff =
		([
			"caster":me,
			"who": 	me,
			"type":"criticalup",
			"att":	"bless",
			"name":	"九阴剑法·碧映光寒",
			"buff1":"feat/critical",
			"buff1_c":1,
			"buff2":"resistance/kee",
			"buff2_c":-30,
			"buff3":"resistance/gin",
			"buff3_c":-30,
			"time":  30,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/ss_bygh",time());
		return 1;
}		
