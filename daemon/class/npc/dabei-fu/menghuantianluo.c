#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int do_pfr(object me, object target);

int do_pfm(object me, object target,int idx)
{
        string msg;
        int l;

        string *style = ({
"火龙吞野－－$N抡动手中$w，棍风呼啸，打向$n的$l！",
"凤羽翩跹－－$N手中$w化做棍影重重，将$n团团围住！",
"虎止咆野－－$N向前一纵，手中$w狂舞，向$n猛扑过去！",
"豹形－－$N欺身急进，手中$w头尾齐出，分打$n的两处要害！",
"断鹤续凫－－$N手中$w一顿，暗蓄内力，点向$n的$l！",
"猿形－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！",
"蛇形－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的$l！",
"鹰形－－$N身形纵起，手中$w自上而下，迅猛无比，砸向$n的$l！"});

        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
                return 0;

        msg = HIY+style[idx]+NOR;

        me->stop_busy();
        l = target->query("kee");
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (me->is_busy())
                return 1;               // Parry busy
        me->start_busy(3);      
        if (target->query("kee") < 1)
                return 1;               // Unconcious / Dead
        if (l == target->query("kee"))
                return 1;               // Miss
        if (me->query("force") < 50)
                return 1;               // Miss
        me->add("force",-50);
        
        if (idx == 7)
        {
                message_vision(HIG"\n$N独自使过一轮「万类霜天竟自由」，身形渐渐稳定下来。\n"NOR,me,target);
                call_out("do_pfr",1,me,target);
                return 1;
        }

        do_pfm(me,target,idx+1);
}


int do_pfr(object me, object target)
{

        message_vision(HIG"$N深吸了一口长气，身形一拢即分，再次化作一片人影环在$n身侧！\n"NOR,me,target);
        call_out("do_pfm",1,me,target);
        return 1;
}

int do_pfx(object me, object target)
{
        message_vision(HIY"$N陡然大喝一声，使出了似是而非的一式「万类霜天竟自由」！\n"NOR,me,target);
        do_pfm(me,target,0);
        return 1;
}


int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「梦幻天罗」只能对战斗中的对手使用。\n");

//      message_vision(HIY"$N手中"+me->query_temp("weapon")->name()+HIY"在地上连点，身形渐散，化作七八个人影绕着$n，令人觉得恍如梦幻。"NOR);
        message_vision(HIG"\n$N手中"HIG"青竹杖"HIG"在地上连点，身形渐散，化作七八个人影环绕$n。\n"NOR,me,target);
        call_out("do_pfx",1,me,target);
        return 1;
}


