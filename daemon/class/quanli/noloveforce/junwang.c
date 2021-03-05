// speed.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
	notify_fail("你只能提升自己的食物。\n");

        if( (int)me->query("force") < 200 )     return 
	notify_fail("你的内力不够。\n");
              skill = me->query_skill("noloveforce",1);
	if(skill < 50) return notify_fail("你的忘情天书太差了！\n");

      me->add("force", -200);
        message_vision(
                CYN
"$N暗暗地聚气凝神，[君王]一出，谁可及！\n" NOR, me);
        me->set("food", 200);
        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

