#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill;
        mapping buff;
        
		skill=me->query_skill("lingxi-zhi",1);
		if (skill<160 && userp(me))
			return notify_fail("心有灵犀需要160级灵犀指法。\n");
		if (ANNIE_D->check_buff(me,"parry_busy"))
			return notify_fail("你已经在使用类似的武功了。\n");
			
		tell_object(me,HIW"你的脑海中豁然一片空明，对方一举一动无不被你算中。\n"NOR);
		buff =
			([
				"caster":me,
				"who":	me,
				"type": "parry_busy",
				"att":"bless",
				"name":"灵犀指·心有灵犀",
				"buff1":"xinyoulingxi",
				"buff1_c": 1,
				"time": 10,
				"buff_msg":"",
			]);
		ANNIE_D->buffup(buff);	
		
	    if (me->is_fighting()) me->start_busy(2);
	    return 1;
}
