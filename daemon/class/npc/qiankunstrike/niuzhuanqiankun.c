// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int mine,yours;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［扭转乾坤］只能对战斗中的对手使用。\n");
	mine = (int) me->query("force_factor");
	yours = (int) target->query("force_factor");
	message_vision(HIW"\n$N突然暴喝一声：扭－－转－－乾－－坤！！！\n\n",me);
	if(random(mine) > yours)
	{
		me->add("force_factor",yours/2);
		msg= HIY "$N将乾坤大挪移掌中的［扭转乾坤］使出，双掌夹带着$n的内力击向$n" NOR;
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->start_busy(2);
		me->add("force_factor",-yours/2);
	}		
	else
	{
		target->add("force_factor",mine/2);
		msg= HIY "$N趁着$n暴喝之际，单腿直踢，以迅捷无比的速度功向$n！" NOR;
                COMBAT_D->do_attack(target,me, TYPE_PERFORM,msg);
                target->add("force_factor",-mine/2);

	}
	return 1;
}
