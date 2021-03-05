
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
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『焚琴』只能对战斗中的对手使用。\n");

        if (me->query_skill("beilongblade",1) < 200 && userp(me))
                return notify_fail("你对悲龙刀法掌握不足，无法使用『焚琴』。\n");
        
        extra = me->query_skill("blade");

        msg = HIR BLK"\n$N";
        msg +=HIR BLK"眼神忽然锐利起来，手中长刀在一瞬间已然出鞘，甚至连阳光也跟不上刀的轨迹，\n只能见到一道灰色的阴影随着刀锋射出。紧接着在长刀斩过的空间里，空气仿佛突然\n被撕碎，被挤压，暴发出尖锐的啸叫，一股匹练似的疾风随着$N"HIR BLK"晃身踏步前斩的动作，\n以无可阻挡之势穿越而过！\n\n";
        msg += HIB"－－－－－－－－－－－－－　　煮　鹤　焚　琴　！\n\n"NOR;

        pp=random(random(random(random(extra*40))))+1;
        pd=random(random(random(random(random(extra*80)))))+1;
        // 极不稳定……极小机会出现超高伤害。
        me->add_temp("apply/attack",pp);
        me->add_temp("apply/damage",pd);        
		message_vision(msg, me, target);
		
    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");

        me->add_temp("apply/attack",-pp);
        me->add_temp("apply/damage",-pd);       

        me->perform_busy(2);
        
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

