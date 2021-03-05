// silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("fire-strike",1);
	if ( extra < 100) return notify_fail("你的［火焰掌法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［烈焰］只能对战斗中的对手使用。\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIR  "$N忽然化作一团熊熊的烈焰，那团厉火直向$n卷去！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "青焰中一点火星飞出，直打$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "如灿烂的杜鹃，火焰四射，在$n的面前盛开！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}

