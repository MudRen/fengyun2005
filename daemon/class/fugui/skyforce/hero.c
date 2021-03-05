// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill,timer,duration;
    	string msg;
    	mapping buff;
    
    	if( target != me ) 
        	return notify_fail("『欢乐英雄』只能用在自己身上。\n");
   	    	
    	skill = me->query_skill("skyforce",1);
    	if (skill < 160)
    		return notify_fail("『欢乐英雄』需要160级的碧空心法。\n");
    	    	
    	timer = 300;		
		duration = me->query("timer/pfm/fg_afo")+timer-time();
		if (duration>0)
    		return notify_fail("你真气已散，再次使用『欢乐英雄』（需"+duration+"秒）。\n");
    		
    	if( me->query("force") < 100 )
        	return notify_fail("『欢乐英雄』至少需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

		if (ANNIE_D->check_buff(me,"fg-afo"))
			return notify_fail("你已经在使用『欢乐英雄』心法了。\n");

    	msg = BGRN + HIW"$N忽然笑了，那是一种充满信心、勇气，如寒冰在春水中融化的欢笑。\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"fg-afo",
			"att":"bless",
			"name":"碧空心法·欢乐英雄",
			"buff1":"pfm/fg-afo",
			"buff1_c":1,
			"time":  30,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		
		me->set("timer/pfm/fg_afo",time());
    	return 1;
    	
}