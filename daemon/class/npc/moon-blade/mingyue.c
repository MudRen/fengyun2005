#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string dodskill,msg;
        int extra, busy,busy2,pp=0,pd=0;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        if( !target
        || 		!target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『明月几时有』只能对战斗中的对手使用。\n");

        if (me->query_skill("moon-blade",1) < 100 && userp(me))
                return notify_fail("你的圆月魔刀还不够精纯，不能出明月几时有（需100级）。\n");
        
        extra = me->query_skill("moon-blade",1)*2;
	
        message_vision(HIW"\n\n$N"HIW"大喝一声，身形在$n"HIW"面前一闪。
"HIR BLK"虽然谁也没有看清楚怎么回事，但谁都可以感觉到，$N"HIR BLK"已然出刀！
"HIY"－－　　明	月	几	时	有　－－\n"NOR,me,target);

        pp=random(random(random(random(extra*40))))+1;
        pd=700+random(random(random(random(random(extra*80)))))+1;
        // 极不稳定……极小机会出现超高伤害。
        me->add_temp("apply/attack",pp);
        me->add_temp("apply/damage",pd);        
	    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
        me->add_temp("apply/attack",-pp);
        me->add_temp("apply/damage",-pd);       

        me->perform_busy(2);
        return 1;
}
