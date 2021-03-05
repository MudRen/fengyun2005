 
#include <ansi.h>
 
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
                return notify_fail("你只能从战斗中领悟燕十三剑法的「第十五式」\n");
 
        extra = me->query_skill("13-sword",1) ;
        if ( extra < 140) return notify_fail("你还没有领悟出燕十三剑法的「第十五式」\n");

        msg = WHT"$N剑尖忽然起了奇异的震动。剑尖本来是斜斜指向$n，震动一起，万物忽然间全都静止。\n就连周围的空气，都彷佛也已停顿。 "
RED"\n没有任何言语可以形容这种情况，只有一个字...\n\n一个很简单的字——死！ \n"HIB"流水乾枯，变化穷尽，生命终结，万物灭亡！\n"NOR;
	weapon=me->query_temp("weapon");
        message_vision(msg, me, target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target,weapon :), random(5)+6);

        me->start_busy(6);
        target->start_busy(4);
        return 1;
}
        
void kill_him(object me, object target,object weapon)
{
        string msg;
        int extra;

        extra = me->query_skill("13-sword",1) ;
        if(extra>160){extra=160+random((extra-160)/4);}
        if(random(extra-140)>5  ) {
        if(me->is_fighting() && target->is_fighting() &&
	        environment(me) == environment(target))
		{
                msg = RED"当$N手里"+weapon->name()+"开始有了生命时，$n就已死了，已无法再有任何变化。 \n"NOR;
                message_vision(msg, me, target);
                target->set_temp("last_damage_from",me);
		target->die();
            
		}
        } else {
                msg = HIR"$N一剑失去目标，忽然觉得灵魂仿佛被抽入"+weapon->name()+"再也无法控制！ "
 RED"\n一股杀气从"+weapon->name()+"反窜回来，针一样刺入$N心脏。 "
 RED"直到$N倒下去，直到$N的心跳已停止，呼吸已停顿，$N手里的"+weapon->name()+"还是震动不停。 "NOR;
                message_vision(msg, me, target);
                me->die();
        }
        
        return ;
}
