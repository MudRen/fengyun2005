#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「落日」只能对战斗中的对手使用。\n");
        
        me->add_temp("apply/attack",extra/7);
        me->add_temp("apply/damage",extra/2);
        
        msg = HIG  "\n$N仰天灌下一口竹叶青，一把将羊皮酒袋抛开，借着酒兴攻向$n，一边纵声长歌：\n" NOR;
        message_vision(msg,me,target);
        msg = HIC    "　　　　一身托天地，\n　　　　　　　　　　　　醒醉寄浮舟。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "　　忽然酹中流，\n　　　　　　　　　　扣舷发狂歌。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "　　　　歌尽续长笑，\n　　　　　　　　　　　　浪子意如何？\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "　　回首所来路，\n　　　　　　　　　　灼灼日已没！\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (me->query_busy()<3) 
                me->start_busy(3);
        me->add_temp("apply/attack",-extra/7);
        me->add_temp("apply/damage",-extra/2);
        return 1;
}

