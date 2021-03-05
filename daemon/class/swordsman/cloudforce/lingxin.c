// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
		notify_fail("你只能用淡云心法的［灵心术］提升自己的智力。\n");
	if (me->query_skill("cloudforce")<80)
		return notify_fail ("你的淡云心法不够高深.\n");
	if( (int)me->query("force") < 300 )    
	        return 	notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("lingxin") ) return 
		notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("cloudforce",1);

        me->add("force", -300);
        message_vision(
                HIR 
"$N微微凝神，运起淡云心法的［灵心术］，头顶上出现一丝淡淡的白雾！\n" NOR, me);

        me->add_temp("apply/intelligence", skill/80);
        me->set_temp("lingxin", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/80 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/intelligence", - amount);
        me->delete_temp("lingxin");
        tell_object(me, "你的［灵心术］运行完毕，将内力收回丹田。\n");
}
 
