// Silencer @ FY4 workgroup. Aug.2004
//  add some kee, but shorter duration than dwg's buffup.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, amount, wolf;
    	string msg;
    	mapping buff;
    
    	if (me->query("class")!="wolfmount")
    		return notify_fail("『虎踞』是狼山特有武功。\n");
    	
    	skill = me->query_skill("xueyeqianzong",1);
    	if (skill < 130)
    		return notify_fail("『虎踞』需要130级的雪野潜踪。\n");

		if(!target ) target=me;    			
    	if( target != me )
        	return notify_fail("你只能用雪野潜踪提升自己的气血值。\n");
    	    	
    	if (ANNIE_D->check_buff(me,"gks"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

	
		if (me->query_temp("pfm/wm_stance"))
			return notify_fail("你无法同时使用不同的雪野潜踪的身法。\n");
		  	
    	msg = BBLU + HIW"$N身形一沉，满弓待发，犹如盘龙虎踞于天地之间，气势不怒而威。\n" NOR;

		wolf = me->query_skill("summonwolf",1);
		amount = 400;
		
		if (skill >=160){
			if (me->query("scroll/xueyeqianzong_feline")==3)		amount = 1300;
			else if (me->query("scroll/xueyeqianzong_feline")==2)	amount = 800;
		}
	
		buff =
			([
				"caster": me,
				"who":  target,
				"type": "kee",
				"att":	"bless",
				"name":	"雪野潜踪·虎踞",
				"buff1":"kee",
				"buff1_c":amount,
				"buff0": "pfm/wm_stance",
				"buff0_c": 1,			
				"time":  600 ,
				"buff_msg": msg,
				"special_func":1,
			]);
			
		ANNIE_D->buffup(buff);
	
    	return 1;
}