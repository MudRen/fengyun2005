// powerfade.c

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill, num;
        
        if ( !target) target = me;
        if( target != me ) 
        	return notify_fail("你只能用九阴心经压制自己的杀气。\n");

 		if (me->query_skill("nine-moon-force",1) < 80)
        	return notify_fail("『内纳术』需要８０级的九阴心经。\n");
               
        if(me->query("bellicosity") <= 0 )
                return notify_fail("你现在毫无杀气。\n");
        
        if( me->query("force") < 50 )     
        	return notify_fail("『内纳术』至少需要50点内力。\n");
        me->add("force",-50);
		me->set("bellicosity",0);
		
		message_vision(BGRN + HIW"$N双眼微合，施展九阴心经内纳之术，放慢呼吸，开始收敛自己的阴气。。。\n" NOR, me);
	
		me->start_busy(1);   
        return 1;
}

 
