//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus;

        if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");  
        
        extra = me->query_skill("enmeiryu",1);
        if(extra<50) return notify_fail("无空波需要50级的陆奥圆明流拳。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("无空波只能对战斗中的对手使用。\n");

	extra = me->query_skill("enmeiryu",1) + F_LEVEL->get_level(me->query("combat_exp"))*3/2;
	
        if(!me->query("mark/true_mukuha")||userp(me)) 
        {
                me->add_temp("apply/attack", extra);    
        	me->add_temp("apply/damage", extra);
               	msg=HIR"$N悠地欺近$n，双拳贴在$n的衣服上，在双拳接触身体的一瞬间
使出了陆奥圆明流的秘奥义『无空波』。\n"NOR;
               	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        	me->add_temp("apply/attack", -extra);
        	me->add_temp("apply/damage", -extra);
        	me->perform_busy(2);
        	return 1;
        }
        
//	此perform在游戏中尚不存在。        
        message_vision(CYN"$N悠地欺近$n，双拳贴在$n的衣服上，在$n的耳边轻声说：\n"
HIR"“我要用你的血把月亮染红！”。 \n"HIG"
「虎砲」！$n看破了$N这一招。 
$n轻巧地将身体朝旁边移了一寸，堪堪躲过了$N这一击。 \n"NOR,me,target);
	me->start_busy(4);
    	call_out("begin_perform",4,me,target);
        return 1;
        
}     


int begin_perform(object me,object target)
{
	
        if( !target || environment(target)!= environment(me)) return 0;

	message_vision(HIR"$N突然觉得胸口一阵巨痛，接着眼前一黑。 \n"NOR,target);
	if (environment(me)==environment(target))
	{
		tell_object(target,HIR"你神智恍惚之际，耳边隐约传来"+me->query("name")+"的话：“无空波是躲不掉的！”\n"NOR);
		tell_object(me,HIC"你在"+target->query("name")+"的耳边轻声说道：“无空波是躲不掉的！”\n"NOR);
	}
	target->unconcious();			
        return 1;
}
