#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
    	int skill;
    	string msg;
    	mapping buff;
		function f;
   
		if (me->query_skill("gaunforce",1) < 200)
        	return notify_fail("『碎玉断空烈诀』需要以200级的碎玉神罡为基础。\n");
        	
    	if( me->query("force") < 500 )
        	return notify_fail("『碎玉断空烈诀』需要500点的内力。\n");
    	
    	if (ANNIE_D->check_buff(me,"powerup"))
    	       	return notify_fail("你已经在运用类似的武功了。\n");
		
    	if (userp(me))
    		me->add("force", -500);

    	msg = HIR "$N长吸一口真气，身形暴长，额上青筋条条浮现。\n" NOR;
	
		f = (: call_other, __FILE__, "fullnpc",me,me->query("force_factor") :);

		me->set("old_force_factor",1);	// 防止ppl通过quit来保持factor-up.

		me->set("force_factor",me->query("force_factor")*3/2);

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup",
			"att":"bless",
			"name":"碎玉神罡·碎玉断空烈诀",
			"time": 20,
			"buff_msg": msg,
			"finish_function":bind(f, this_object()),
		]);
		ANNIE_D->buffup(buff);
	
    	if( me->is_fighting() && userp(me)) 
    		me->start_busy(1);

    	return 1;
}



void fullnpc(object target,int i)
{
	if (!target)
		return;
	target->set("force_factor",i);
	return;
}

 

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
