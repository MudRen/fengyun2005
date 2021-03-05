// speed.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
	notify_fail("你只能提升自己的速度。\n");

        if( (int)me->query("force") < 100 )     return 
	notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("speedup") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("noloveforce",1);
	if(skill < 60) return notify_fail("你的忘情天书太差了！\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N暗暗地聚气凝神，[风流]一出，谁可及！\n" NOR, me);
        me->add_temp("apply/agility", skill/10);
        me->set_temp("speedup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/20 :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/agility", - amount);
        me->delete_temp("speedup");
        tell_object(me, "你的[风流]运行完毕，整个人又松懈了下来。\n");
}
 
