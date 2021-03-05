// void_sense.c

#include <ansi.h>
inherit SSERVER;

int	shade_done(object me, object caster);

int conjure(object me, object target)
{
	int lvl,i,duration;
	object env, *inv;
	string msg;
	mapping buff;
		
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才可以使用『隐识』\n");
	
	lvl = me->query_skill("essencemagic",1);
	if ( lvl < 60)
        return notify_fail("『隐识』需要60级八识神通！\n");
	
/*	if (me->is_fighting())
		return notify_fail("『隐识』不能在战斗中使用。\n");*/
		
	if(ANNIE_D->check_buff(me, "invisible"))
   		return notify_fail("你已经在隐身了。\n");
    
    duration = me->query("timer/no_shade")+ 600 - time();
    if (duration>0)
    	return notify_fail("你的隐识被破，短时间（"+ duration/60+"分钟）内无法再次使用\n");
                
	if(me->query("atman") < 100 )
		return notify_fail("需要100点的灵力！\n");
    me->add("atman", -100);
	
	msg = HIW "$N凝神提气，一团白芒乍出体内，整个人渐渐虚化．．．\n" NOR;

	buff =
		([
			"caster":me,
			"who": me,
			"type":"invisible",
			"att":"bless",
			"name":"八识神通·隐识",
			"env_type": "invisibility",
			"env_type_c":1,
			"time":  300,
			"buff_msg":  msg,
			"disa_type": 2,		// 非正常中断时也要执行 shade_done
			"finish_function": (: shade_done :),
		]);
	ANNIE_D->buffup(buff);
	if (me->is_fighting() ) me->start_busy(3);
	return 1;
}


int	shade_done(object me, object caster)
{
        if (!me || !caster)	return 1;
        message_vision(HIG "$N的身形渐渐地显现出来。\n" NOR, me);
        me->add_temp("block_msg/all",1);
        me->move(environment(me));
        me->add_temp("block_msg/all",-1);
        me->perform_busy(2);
		return 1;
}
