// annie 6.27.03
// MANAFLARE - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「有无相生」只能对战斗中的对手使用。\n");

	if (!target->query("force"))
		return notify_fail("「有无相生」无法对对方使用。\n");

	message_vision( HIR BLK"\n$N暗运玄功，抑、反、逆三诀集于一掌叩向$n气海。\n"NOR,me,target);
	message_vision( WHT
"$n闪躲不及，被一掌击中要害，顿时内息激荡，气血翻涌。\n" NOR, me,target);
	
	target->receive_damage("kee",target->query("force")*(1+random(3)),me);
	target->receive_wound("kee",target->query("force")*(1+random(3))/3,me);
	target->set("force",0);
    COMBAT_D->report_status(target);
	me->perform_busy(2);
	return 1;
}

