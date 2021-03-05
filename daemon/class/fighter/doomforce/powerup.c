// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill;
    	string msg;
    	mapping buff;
    
    	if( target != me ) 
        	return notify_fail("吹血神功只能用来提升自己的战斗力。\n");
   	    	
    	if (ANNIE_D->check_buff(me,"powerup")
    		|| ANNIE_D->check_buff(me,"dodgeup")
    		|| ANNIE_D->check_buff(me,"atkup"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	skill = me->query_skill("doomforce",1)/2;
    	if( me->query("force") < 100 )
        	return notify_fail("需要100点的内力。\n");
    	if (userp(me)) {
//    		if (!me->is_fighting())	me->add("bellicosity", 100+skill);
    		me->add("force", -100);
    	}

    	msg = BGRN + HIW"$N长身直立，渐入忘我之境，唯有眼神炽热，剑何在？
人即是剑，只要人在，天地万物，都是$N的剑。\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"吹血神功·傲天诀",
			"buff1":"apply/attack",
			"buff1_c":skill,
			"buff2":"apply/dodge",
			"buff2_c":skill,
			"time": 300,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
	me->perform_busy(1);

    	return 1;
    	
}