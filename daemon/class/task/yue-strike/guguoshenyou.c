/*	
An old redundant perform.. NPC only. Silencer @ FY4 workgroup. Aug.2004
雄气堂堂贯斗牛，誓将直节报君仇。
斩除顽恶还车驾，不问登坛万户侯。
*/


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        
	if (userp(me) && !wizardp(me))
		return notify_fail("你所选的武功中没有这种必杀技。\n");
	
	extra = me->query_skill("yue-strike", 1);
        if ( extra < 150) 
        	return notify_fail("你的小重山掌还不够纯熟！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『故国神游』只能对战斗中的对手使用。\n");
        
        
        me->add_temp("apply/damage",extra/2);
        me->add_temp("apply/attack",extra/4);
        
        msg = HIY  "$N仰天长叹，使出了小重山掌的『故国神游』，一股浩然正气直冲霄汉！\n" NOR;
        message_vision(msg,me,target);
        msg = HIR  "雄气堂堂贯斗牛" NOR;
		msg+= "\n$N运足内劲，双掌齐出，直取$n的$l。";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIW  "      誓将直节报君仇" NOR;
		msg+= "\n$N右臂如环般圈住$n的手臂，左手毫不客气的一拳击向$p。";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIM  "            斩除顽恶还车驾" NOR;
		msg+= "\n$N出手如电，转眼间双掌已经出现在$n的面前！";
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIB  "                  不问登坛万户侯" NOR;
		msg+= "\n$N身形一折，凌空下击，$n简直都不知该如何躲避！";
		me->add_temp("apply/damage",extra/2);
		me->add_temp("apply/attack",extra/4);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->start_busy(2);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra/2);
        return 1;
}

