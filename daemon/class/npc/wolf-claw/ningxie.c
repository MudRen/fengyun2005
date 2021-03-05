
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
    	if(me->query("class")!="wolfmount")
    	return notify_fail("只有狼山弟子才能使出「凝血」的绝技。\n");
    	if((int) me->query("force")<50)
    	return notify_fail("你的内力不够，使不出「凝血」绝技。\n");
	
	
	if( !target ) target = offensive_target(me);
	extra = me->query_skill("unarmed")* 2 ;
	if(extra <= 60 ) return notify_fail("你的「地狱狼魂爪」不够熟练！\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(WHT"「凝血」只能对战斗中的对手使用。\n"NOR);

	
	msg = HIB "$N双爪回环各划一个弧形，一股森森的阴风直扑$n。\n" NOR;
    	if(random(extra*extra/2 + me->query("combat_exp")) 
    		> (int)target->query("combat_exp")) {
		    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg += WHT"\n暗劲袭来，$N只觉得彻骨冰冷，如坠幽冥，混身血液几乎凝固！ \n" NOR;
        	target->receive_wound("sen", ((int) me->query("max_sen")/5), me);
        	target->receive_wound("kee", ((int) me->query("max_kee")/10), me);
        	target->start_busy(2);
    	}
    	else msg += HIY"\n$N连忙腾身后越，闪开了$n暗劲的致命一击。 \n" NOR;

    	message_vision(msg, target, me);
    	me->add("sen",-50);
    	me->add("force",-50);
    	me->start_busy(4);
    return 1;
}