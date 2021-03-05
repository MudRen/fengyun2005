// powerup.c 	+100 atk and dodge

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;

		if (me->query_skill("nine-moon-force",1) < 60)
        	return notify_fail("你的九阴心经尚且不够熟练（需６０级）。\n");
    	
    	if( target != me )
        	return notify_fail("你只能用九阴心经提升自己的战斗力。\n");
    	    	
    	if (ANNIE_D->check_buff(me,"powerup")
    		|| ANNIE_D->check_buff(me,"dodgeup")
    		|| ANNIE_D->check_buff(me,"atkup"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	skill = me->query_skill("nine-moon-force",1)/2;
    	if( me->query("force") < 100 )
        	return notify_fail("『寒阴术』需要100点的内力。\n");
    	if (userp(me)) {
    		me->add("force", -100);
    	}

    	msg = BGRN + HIW"$N"BGRN + HIW"眼观鼻，鼻观口，口观心，施展九阴心经，聚虚为实，全身透出阴寒无比的真气！\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"九阴心经·聚阴诀",
			"buff1":"apply/attack",
			"buff1_c":skill,
			"buff2":"apply/dodge",
			"buff2_c":skill,
			"time": 900,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);

    	return 1;
}
