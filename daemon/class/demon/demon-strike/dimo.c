#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, damage;
	
	extra = me->query_skill("demon-strike",1) ;
	if(userp(me) && extra < 100 ) 
		return notify_fail("『地魔式』需要150级如意地魔连环八掌！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『地魔式』只能对战斗中的对手使用。\n");
	
	damage = me->query_skill("demon-strike",1)*3;

	msg = HIR "\n$N喝道：『九天十地，诸神之子，遇难遭劫，神魔惧泣』
倏然间双臂暴长，一招『地魔式』，双手拢向$n！" NOR;
	if(random( 3*me->query("combat_exp")) >= (int)target->query("combat_exp"))	{
		message_vision(msg+"\n",me,target);
		message_vision( HIB "$N躲闪不及，全身正被掌影罩住！ 一股蓝气从顶门喷涌而出！\n" NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "gin", damage);
		target->receive_damage("gin",damage, me);
		me->receive_fulling("gin",damage/2, me);
		COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
	}	
	else{
        	me->add_temp("apply/attack",extra);
        	me->add_temp("apply/damage",extra);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra);
        	me->add_temp("apply/damage",-extra);
	}
	me->perform_busy(2);
	return 1;
}



