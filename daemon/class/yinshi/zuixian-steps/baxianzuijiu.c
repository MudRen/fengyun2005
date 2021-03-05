#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill;
	string msg;
	mapping buff;
	
	skill = me->query_skill("zuixian-steps", 1);
	if(skill < 100) return notify_fail("『八仙醉酒』需要100级的醉仙望月步！\n");
                
        if(target && target != me )
        	return notify_fail("你只能将『八仙醉酒』用在自己的身上。\n");
	
	if (ANNIE_D->check_buff(me, "dodgeup")
        	|| ANNIE_D->check_buff(me, "powerup"))
               	return notify_fail("你已经在施展类似的武功了。\n");
	
	if( (int)me->query("force") < 100 )     
        	return notify_fail("八仙醉酒需要消耗100点内力。\n");
        if (userp(me))	me->add("force", -100);
	
	skill = skill/2;
	
	msg = BGRN + HIW "$N身子东倒西歪，有如喝醉了酒，站立不稳。整个身形飘逸不定，
俨然是醉仙望月步中的『八仙醉酒』\n\n" NOR;

        buff =
		([
			"caster": me,
			"who":  me,
			"type": "dodgeup",
			"att":	"bless",
			"name":	"醉仙步·八仙醉酒",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time":  900 ,
			"buff_msg": msg,
		]);
		
        ANNIE_D->buffup(buff);
		me->perform_busy(1);
        return 1;
        
}
