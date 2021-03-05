#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
	string msg;
	int extra,n;
	object weapon;
	extra = me->query_skill("xuanyuan-axe",1);
	if ( extra < 40) return notify_fail("『鬼斧神工』至少需要40级的轩辕斧法！\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "longlife-force")
		return notify_fail("轩辕斧法需要苍生诀的配合！\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『鬼斧神工』只能对战斗中的对手使用。\n");
		
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	target->set_temp("no_check_pfm_win",1);
	
	msg = HIY  "$N"HIY"气沉丹田，怒吼声中手中的"+ weapon->name()+HIY"雷霆霹雳般向$n"+HIY"砍出一斧『鬼斧』\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	target->set_temp("skip_damage_record",1);
        msg = HIY  "\n$N"HIY"筋骨格格直响，双臂骤然变粗，手中的"+ weapon->name()+HIY"回飞，旋风般的又是一斧『神工』\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        
        me->add_temp("apply/attack",-extra);
    
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(2);
	return 1;
}

