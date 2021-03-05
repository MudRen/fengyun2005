#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, hammer;
    	object weapon;
    	int busy, super;
    	
    	if( !target ) target = offensive_target(me);
		if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        	return notify_fail("『天雷一击』只能对战斗中的对手使用。\n");
        
    	weapon = me->query_temp("weapon");
    	extra = me->query_skill("thunderwhip",1);	// 200 *1.6
    	    	
    	if( extra <50) return notify_fail("『天雷一击』至少需要50级的天雷破！\n");

    	if( extra < 200 || me->query("class")!= "yinshi")
    	{
            me->add_temp("apply/attack", extra);
        	me->add_temp("apply/damage", extra);
        	msg = HIR"\n$N"+HIR"力灌鞭梢，手中的"+weapon->query("name")+
            		HIR"＂叭＂的一声，象条毒龙般向$n"NOR+HIR"钻去！\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	me->perform_busy(2);
    	}	
    	else	{	  		
   			
   			me->add_temp("apply/attack", extra);
        	me->add_temp("apply/damage", extra);
        	msg = HIR"\n$N"+HIR"力灌鞭梢，手中的"+weapon->query("name")+
            		HIR"＂叭＂的一声，象条毒龙般向$n"NOR+HIR"钻去！\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
               	
        	msg = HIR"\n$N"+HIR"急运真气，大喝一声，手中的"+weapon->query("name")+
            		HIR"夹着惊雷之势向$n"NOR+HIR"反卷而去！\n" NOR;
        	message_vision(msg,me,target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	
	    	busy = 2;
	    	super = me->query_skill("flying-dragon",1);
	    	if (super >=100) {
	    		super = (super-100)/10;
				if (random(100)<super && me->query_temp("yl9x_times") < 2 )	{
					me->add_temp("yl9x_times",1);
					message_vision(WHT"$N一口真气吐出，身法竟然丝毫不显迟滞。\n"NOR, me);
					busy = 0;
				} else {
					me->set_temp("yl9x_times",0);
				}
			}

        	me->perform_busy(busy);
   		}
	return 1;
}
