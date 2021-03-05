
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「抱残守缺」只能对战斗中的对手使用。\n");

          if (target->query_temp("buff/no_abs"))
                return notify_fail("对方已经中了「抱残守缺」，还不抓紧时机攻击？\n");

                i = target->query_skill("iron-cloth") + target->query_temp("apply/iron-cloth");
                if (!i)
                return notify_fail("现在没有必要施展「抱残守缺」。\n");

    message_vision( CYN
"$N身影一闪，忽然欺近$n身前，柔若无骨的手指轻轻拂上$n的胸膛，一路叩击着下滑到气海丹田。\n" NOR, me,target);
    message_vision( YEL
"$n变得面如土色，浑身如筛糠般狂抖，护身的硬功竟在这一瞬间已被$N破去。\n" NOR, me,target);

                target->add_temp("buff/no_abs",1);
                me->start_busy(2);
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
                         i :), 30);
    return 1;
}

void remove_effect(object me,int amount)
{
    if (!me)	return;
    me->add_temp("buff/no_abs",-1);
    tell_object(me, "你骨节中的酸麻之感渐渐退去了。\n");
}
 

