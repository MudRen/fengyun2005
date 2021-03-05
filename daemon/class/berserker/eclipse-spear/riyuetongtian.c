#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        object *pros;
        extra = me->query_skill("eclipse-spear",1);
        if ( extra < 150) return notify_fail("你的朔望长枪还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"日月同天"NOR"只能对战斗中的对手使用。\n");
        
        msg = HIC"$N"HIC+me->query_weapon()->name()+"乍现手中，一击＂日月同天＂，枪影重重带出森森寒气，劈头盖脸倾泻而下。\n"NOR;
		message_vision(msg, me, target);
		
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/damage", -extra);

        if (target->query_temp("damaged_during_attack"))
        {
                me->perform_busy(3);
                return 1;
        }

        if (me->is_busy())
        {
                me->perform_busy(3);
                return 1;
        }

        message_vision(HIW"$n"HIW"接住一招，飞身疾退，意图闪开$N连绵攻势。\n",me,target);

        msg = HIC"$N"HIC+"提气急追，如影随形跟上去，照模照样，原封不动又是一击＂日月同天＂。\n"NOR;
		message_vision(msg, me, target);
		
        me->add_temp("apply/damage", extra*3);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/damage", -extra*3);

        if (target->query_temp("damaged_during_attack"))
        {
                me->perform_busy(3);
                return 1;
        }

        if (me->is_busy())
        {
                me->perform_busy(3);
                return 1;
        }

        message_vision(HIW"$n"HIW"先退三尺，又退三丈，背后已无退路！\n",me,target);

        msg = HIC"\n$N"HIC+"第三枪又到，还是居高临下，还是长江大河般攻来，还是那式＂日月同天＂。"NOR;
        message_vision(msg,me,target);

        msg = BRED HIW"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n";
        msg += "　　　　　日　　月　　同　　天　　，　　退　　无　　可　　退　　！　　\n";
        msg += "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"NOR;

        target->add_temp("is_unconcious",1);
        pros = target->query_temp("protectors");
        target->delete_temp("protectors");
        
        me->add_temp("apply/damage", extra*8);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage", -extra*8);

        target->add_temp("is_unconcious",-1);
        target->set_temp("protectors",pros);

        target->stop_busy();    // Cancel Busy.
        msg = HIR"$N"HIR"脸色煞白，双臂上举，猝然反击，意在两败俱伤！"NOR;
        
        me->add_temp("is_unconcious",1);
        pros = me->query_temp("protectors");
        me->delete_temp("protectors");
        
        target->add_temp("apply/damage", extra*7);
        COMBAT_D->do_attack(target,me, TYPE_PERFORM,msg);
        target->add_temp("apply/damage", -extra*7);

        me->add_temp("is_unconcious",-1);
        me->set_temp("protectors",pros);
                
        me->perform_busy(3);

        return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

