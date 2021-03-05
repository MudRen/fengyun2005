// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, ratio, amount, atman;
        
        skill = me->query_skill("ghosty-steps", 1);
		if(skill < 150) 
			return notify_fail("太虚百幻需要150级的太虚幻步！\n");
	
        if (!target) target = me;
        if( target != me ) 
        	return 	notify_fail("你只能将太虚百幻用在自己的身上。\n");
        
        atman = me->query("atman");
        if (atman<10)
        	return notify_fail("你魔力将尽，太虚百幻无功而返。\n");
	
        message_vision( BGRN + HIW "$N轻啸一声，化作数道身影，籍太虚百幻之步法吐纳气息！\n" NOR, me);
        
        ratio = skill * 100 /300;        
        
        amount = atman * ratio /100;
        
//      write ("amount is "+ amount +"\n");
        
        call_out("take_effect", 2, me, amount);
        me->set("atman",0);	
        me->perform_busy(1);     
        return 1;
}

int	take_effect(object me, int amount)	{
		
		if (!me || me->is_ghost())	return 1;
		
		if (me->query("force")+ amount > me->query("max_force")*2)
       	me->set("force",me->query("max_force")*2);
        else
        	me->add("force",amount);
		tell_object(me, "你的气息调匀完毕，恢复了部分内力。\n"); 
		me->force_status_msg("force");       	
		return 1;
}
	