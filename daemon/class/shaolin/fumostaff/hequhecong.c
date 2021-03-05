// Silencer@fengyun	June.2005
//	enhance = 250;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int extra, busy, mod, enhance;
    	object weapon;
    
    	if (me->query("class")!="shaolin")
    		return notify_fail("『何去何从』是少林武功。\n");
    	
    	extra = me->query_skill("fumostaff",1);
    	if (me->query_skill("staff",1) < 150 || extra<150) 
    		return notify_fail("『何去何从』需要150级的韦陀伏魔杖法和150级基本杖法。\n");
      
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||!me->is_fighting(target) )
        return notify_fail("『何去何从』只能对战斗中的对手使用。\n");
        
    	if(target->is_busy())
	        return notify_fail("对方已经手忙脚乱了！\n");

    	mod = COMBAT_D->can_busy(me, target, "fumostaff");	
		if (!mod)
			return notify_fail(HIW"对手功力深湛，不会被此杖法迷惑的。\n"NOR);

    	weapon = me->query_temp("weapon");
    
    	message_vision(HBRED+HIW"\n苦海茫茫，何处是岸？$N"HBRED+HIW"手中的"+weapon->name()+ HBRED+HIW"忽然幻出十数个『茫』字！\n"NOR,me);

		if (COMBAT_D->do_busy_attack(me, target, "fumostaff", "step", 200, mod)) 
    	{
			target->force_busy(3);
			target->set_temp("busy_timer/fumostaff",time());
			message_vision(YEL"$N被杖法所惑，动作慢了下来！\n\n"NOR,target);
    		    		
    		if (userp(me) && !me->query("pfm/fumo_improve"))
    			me->perform_busy(1);
    	}
    	else
    	{
			message_vision(HIR"$N忽然整个人飞起贴在杖上，$n的杖花顿时消失无踪！\n\n"NOR,target,me);		
			me->perform_busy(2);
    	}
    	return 1;
}

