#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, exp_bonus, extra_dam,n,m;
                
        extra = me->query_skill("ironcuff",1);
        if( extra < 100 ) 
                return notify_fail("你的基本功不够扎实，用不出『黑虎掏心』。\n");

        if( me->query("class") || me->query("once_menpai"))
        	return notify_fail("你出身名门，这种平凡无奇的拳法如何能看得上眼？\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『黑虎掏心』只能对战斗中的对手使用。\n");
        
        if (me->query("force") < 500)
                return notify_fail("你的内力不足以使出『黑虎掏心』。\n");
        if (userp(me))
                me->add("force",-500);
        if (userp(me))
                m=6;
        else
                m=8;
        
        msg = "$N大喝一声，使一招平平无奇的「"BLINK"黑虎掏心"NOR"」，对准$n的心口「呼」地就是一拳！";
        n=1;

        if (me->query_temp("timer/ironcuff_heihutaoxin")+ m >time())
        {
                if (me->query_temp("annie/hhtx") == 1)
                {
                        msg = "$N右拳递出，左手再握，还是平平无奇的「"BLINK"黑虎掏心"NOR"」，对准$n的心口又是一拳！";
                        n=2;
                        extra*=4;       // 200 / 400
                }

                if (me->query_temp("annie/hhtx") == 2)
                {
                        msg = "$N一声断喝，双腕齐翻，平平前递，还是那招「"BLINK"黑虎掏心"NOR"」，还是向$n的心口捶去！";
                        n=0;
                        extra*=7;       // 350 / 700
                }
        }
        me->set_temp("annie/hhtx",n);

        me->add_temp("apply/attack",extra/2);
        me->add_temp("apply/damage",extra);
        
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
        me->add_temp("apply/attack",-extra/2);
        me->add_temp("apply/damage",-extra);
        
        me->perform_busy(3-n);
        me->set_temp("timer/ironcuff_heihutaoxin",time());

        return 1;
}


/*

张三笑道：好眼光。
张三道：我这一套铁山破拳，收进的尽是天下俗之又俗的招式，既不花巧，也不好看。
然而俗招之所以成为俗招，就是因为好用，所以常常要用，用多了大家都会，因此而不希奇。
武学大师们无不想自创武功留名，招式难免追求奇巧，倒脱了反朴归真的本意。
正所谓他强任他强，清风拂山岗，他横自他横，明月照大江，真到了战阵之上，什么机变你也不用去管，
只要老老实实地一招一式将这铁山破拳打出，不由得他不手忙脚乱。


*/
