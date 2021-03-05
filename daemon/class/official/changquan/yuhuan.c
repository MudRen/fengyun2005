// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,sklv;
	int orforce, force;
	
	if(userp(me) && me->query("class") != "official")		
		return notify_fail("你不是朝廷官员，不可以用玉环鸳鸯拳。\n");
	extra = me->query_skill("unarmed");
	sklv = me->query_skill("changquan",1);
	if (userp(me) &&extra < 220) 
		return notify_fail("『玉环鸳鸯拳』需要220级有效少林长拳!\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『玉环鸳鸯拳』只能对战斗中的对手使用。\n");
		
	if (me->query("force") < 120)
		return notify_fail ("『玉环鸳鸯拳』至少需要120点的内力。\n");

	orforce = extra/7;
	me->add("force_factor",orforce);
	force = me->query("force");
	
	target->set_temp("no_check_pfm_win",1);
	
	me->add_temp("apply/attack",extra/10);
	msg = HIY  "$N使出少林长拳中的『玉环鸳鸯拳』，一招连环七式向$n攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "上一拳！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
        msg = HIY  "下一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "左一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "右一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "前一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "后一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "最后再一拳！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra/10);
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
		
	if (me->query("force_factor"))
	me->add("force_factor",-orforce);
	me->set("force", force - 120);
	if (sklv >= 250) {
		me->perform_busy(4);
	} else {
		me->perform_busy(5);	      			
	}
	return 1;
}
