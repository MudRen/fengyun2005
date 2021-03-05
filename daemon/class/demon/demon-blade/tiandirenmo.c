// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, step;
	extra = me->query_skill("demon-blade",1);
	if ( extra < 100) 
		return notify_fail("『天地人魔』需要100级的天地人魔连环八式！\n");
	step = me->query_skill("demon-steps",1);
	if ( step < 100) 
		return notify_fail("『天地人魔』需要100级的天地人魔连环八步！\n");
	
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "demon-steps")
		return notify_fail("『天地人魔』需要如意人魔连环八步的配合！\n");
	
	if ( me->query_skill_mapped("force")!= "demon-force")
		return notify_fail("『天地人魔』需要天地人魔心法的配合！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『天地人魔』只能对战斗中的对手使用。\n");
	
	step = me->query_skill("demon-steps",1);
	
	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",step);
	me->add_temp("apply/damage",extra);	
	
	msg = HIY  "\n$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
        
        msg = HIY  "魔焰万丈！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "魔光乍现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔独尊！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "万刃天魔！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔回天！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔七现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "万魔归宗！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-step);
	me->add_temp("apply/damage",-extra);	
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(5);
	return 1;
}
