// powerfade.c

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill,num;
        if( target != me ) 
        	return notify_fail("吹血神功只能用来压制自己的杀气。\n");
        if( (int)me->query("force") < 100 )     
        	return notify_fail("你的内力不够。\n");
        if (me->query("sen")<100)
        	return notify_fail("你的心神不够。\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("你现在毫无杀气。\n");

        skill = me->query_skill("doomforce",1);
	num = 100+skill;
	me->add("bellicosity", -num );
        me->add("force", -100);
        me->receive_damage("sen", 100);
	me->set_temp("last_damage_from","练功不慎");
	
        message_vision( BGRN + HIW"$N微一凝神，运起吹血神功，放慢呼吸，开始收敛自己的杀气。。。\n" NOR, me);
	me->start_busy(2);
        return 1;
}
