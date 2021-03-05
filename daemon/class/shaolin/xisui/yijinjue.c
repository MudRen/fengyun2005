// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	string msg;
	int amount;
	mapping buff;
	
	if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("易筋诀需要120级的洗髓经！\n");
	    
        if (ANNIE_D->check_buff( me, "strup"))
               	return notify_fail("你已经在施展类似的武功了。\n");
	
	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	me->receive_wound("kee", 100);
	
	amount = 5;
	
	buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"strup",
			"att":	"bless",
			"name":	"洗髓经·易筋诀",
			"buff1":"apply/strength",
			"buff1_c":amount,
			"time":  300 ,
			"buff_msg":BGRN + WHT"$N凝神聚力，骨骼咯咯作响，身形居然高大了一截！！\n"NOR,

		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	
	return 1;
}
