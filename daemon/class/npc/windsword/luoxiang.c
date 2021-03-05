// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［沉萼落香］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");

        extra = me->query_skill("sword");
        me->add_temp("apply/attack", extra*2);  
        me->add_temp("apply/damage", extra*4);

        msg = HIR"\n$N"+HIR"突然微笑起来，右手握住"+weapon->name() +HIR"剑柄，顿时光华自鞘中逸出，一闪而没。" NOR;
        target->add_temp("combat_no_report",1);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        message_vision(msg,me,target);
        if (!target->query_temp("damaged_during_attack"))
                message_vision(HIY"\n$n"HIY"急退三步，险险避开了那道疾电寒光。\n\n"NOR,me,target);
        else
        {
                message_vision(HIR"\n只见$n胸前飞散出一片鲜血，仿佛是庭中花树摇落如雨如烟，风尽剑息洒下满地残红。\n"NOR,me,target);
                COMBAT_D->report_status(target);
        }
        target->add_temp("combat_no_report",-1);

        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*4);
        me->perform_busy(2);
        return 1;
}

