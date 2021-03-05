// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
    	int lvl;
    
    	if (me->query("class")!="bonze")
    		return notify_fail("八识神通为兴国绝技。\n");
    	
    	lvl = (int) me->query_skill("essencemagic",1);
    	if (lvl<30) 
    		return notify_fail("需要30级八识神通才能使用寂识神通。\n");
    
    	if (me->is_fighting())
    		return notify_fail("寂识神通不能在战斗中使用。\n");
    
    	if (environment(me)->query("no_fly") )
    		return notify_fail("此地不能使用寂识神通。\n");
        
        if (stringp(me->query_temp("no_move")))
        	return notify_fail(me->query_temp("no_move"));
        	
    	if (target)  
    		return notify_fail("寂识神通只能对自己使用。\n");
    	    	
    	if( me->query("atman") < 100 )
        	return notify_fail("寂识神通需要100点灵力！\n");
    	me->add("atman", -100);
    
    	message_vision(HIB "$N盘膝而座，开始运用寂识神通静思入定 ...\n" NOR, me);
     	
    	if( random(me->query_skill("essencemagic",1)) +14 < me->query_skill("essencemagic",1))
    	{
	 		tell_object(me,WHT"你的周围一片寂静，你感觉身体不断的下沉。\n"NOR);
	 		TASK_D->flying_risk(me);
	 		me->move("/d/death/gate");
	 		me->start_busy(5);
        	return 1;
    	}
    	write("可是什么事情都没有发生。\n");
       	return 1;
}




