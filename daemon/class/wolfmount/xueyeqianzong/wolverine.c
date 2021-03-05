// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, amount,wolf;
    	string msg;
    	mapping buff;
    
    	if (me->query("class")!="wolfmount")
    		return notify_fail("『狼突』是狼山特有武功。\n");
    	
    	skill = me->query_skill("xueyeqianzong",1);
    	if (skill < 50)
    		return notify_fail("『狼突』需要50级的雪野潜踪。\n");
    			
    	if(!target ) target=me;
    	if(target != me )
        	return notify_fail("你只能用雪野潜踪提升自己的战斗力。\n");
    	    	
    	if (ANNIE_D->check_buff(me,"powerup")
    		|| ANNIE_D->check_buff(me,"atkup"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

		if (me->query_temp("pfm/wm_stance"))
			return notify_fail("你无法同时使用不同的雪野潜踪的身法。\n");
			
    	msg = BBLU + HIW"$N俯下身子，骨节喀喀作响，好像变成了一匹狼，一匹孤独、寂寞、寒冷、饥饿的狼！\n" NOR;

		wolf = me->query_skill("summonwolf",1);
		
		amount = 50;
		if (skill >=120)	amount = 80;
		if (skill >=160 && me->query("scroll/xueyeqianzong_wolverine")==3)	amount = 120;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"atkup",
			"att":"bless",
			"name":"雪野潜踪·狼突",
			"buff1":"apply/attack",
			"buff1_c":amount,
			"buff0": "pfm/wm_stance",
			"buff0_c": 1,
			"time": 600,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	return 1;
}
