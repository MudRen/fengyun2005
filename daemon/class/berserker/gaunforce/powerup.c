#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
    
//    	if (me->query_skill("gaunforce",1) < 150)
//        	return notify_fail("『碎玉断空烈诀』需要以150级的碎玉神罡为基础。\n");
        	
    	if( (int)me->query("force") < 100 )
        	return notify_fail("『碎玉焚情灭诀』需要100点的内力。\n");
    	
    	if (ANNIE_D->check_buff(me,"powerup"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");

    	skill = me->query_skill("gaunforce",1)/2;
    	if (userp(me))
		{
    		me->add("bellicosity", skill/2);
    		me->add("force", -100);
    	}

    	msg = HIR "$N"HIR"长吸一口真气，身子里三百多根骨骼发出一阵炒豆爆裂般的声响，手足四肢仿佛又增长了几寸。\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"碎玉神罡·碎玉焚情灭诀",
			"buff1":"apply/attack",
			"buff1_c":skill,
			"buff2":"apply/damage",
			"buff2_c":skill,
			"time": 300,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
