#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("13-sword",1) ;
        if ( extra < 50) return notify_fail("你的燕十三剑法不够纯熟！\n");
                

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［第十四式］只能对战斗中的对手使用。\n");
	
	me->set_temp("14sword",1);
	
       	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra*4);
	msg = YEL"$N的剑势忽然慢了，很慢。一剑挥出，不着边际，不成章法。 \n"
	HIY "只见这笨拙而迟钝的一剑慢慢的刺过来忽然化作了满天的花雨。 \n"NOR;

	COMBAT_D->do_attack(me,target,TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*4);
        if (me->query_busy()<2) me->start_busy(2);
	me->set_temp("14sword",0);
        
        return 1;
}

