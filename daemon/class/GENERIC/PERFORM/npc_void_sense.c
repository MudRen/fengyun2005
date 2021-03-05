// void_sense.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 	int skill;
 	int my_exp,his_exp;
 	object *enemy;

	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
		 	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［空识神通］只能对战斗中的对手使用。\n");
    	
    	if( (int)target->query_temp("voidsense") ) 
    		return notify_fail("敌人已经中招了，还不抓紧时机攻击？\n");
    	
    	message_vision(HIY "$N双手合十，垂眉俯首，低声吟诵 ...\n" NOR, me);
	skill= (int) me->query_skill("essencemagic",1);

	message_vision(HIW"$N心头一颤，只觉繁华世事皆为过眼烟云，身形不由凝滞下来。\n"NOR, target);
	target->add_temp("apply/dodge", -skill);
	target->add_temp("apply/parry", -skill);
	target->add_temp("apply/attack",-skill);
	target->set_temp("voidsense", 1);
	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), skill/4);
	return 1;
}

void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", amount);
        target->add_temp("apply/parry", amount);
        target->add_temp("apply/attack", amount);
        target->delete_temp("voidsense");
        message_vision(HIR"$N浑身一凛，恍若大梦初醒。\n" NOR, target);
}
 
    
    
    