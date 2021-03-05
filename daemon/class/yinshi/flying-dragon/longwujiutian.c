// tie@fengyun
//	atk+350, dmg+200, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, atk;
	
	extra = me->query_skill("flying-dragon",1);
	if( extra <10) return notify_fail("『龙舞九天』需要10级飞龙探云手！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『龙舞九天』只能对战斗中的对手使用。\n");
	
	atk = 50 + extra * 3/2;
		
	me->add_temp("apply/attack", atk);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N"HIR"双手呈鹰爪状，全身腾空，左右掌穿插翻飞，疾向$n"HIR"抓去！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -atk);
	me->add_temp("apply/damage", -extra);
	
	me->perform_busy(2);
	
	return 1;
}


