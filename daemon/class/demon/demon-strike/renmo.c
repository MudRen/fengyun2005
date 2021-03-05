// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, damage;

	extra = me->query_skill("demon-strike",1) ;
	if(userp(me) && extra < 180 ) 
		return notify_fail("『人魔式』需要150级如意地魔连环八掌！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『人魔式』只能对战斗中的对手使用。\n");

	damage = me->query_skill("demon-strike",1)*3;
	
	msg = HIR "\n$N喝道：『九天十地，诸神诸魔，俱来护驾，同登极乐』
倏然间双臂暴长，一招『人魔式』，双手拢向$n！" NOR;
	if(random(3*me->query("combat_exp")) >= (int)target->query("combat_exp"))	{
		message_vision(msg+"\n",me,target);
		message_vision( HIM "$N躲闪不及，全身正被掌影罩住！ 一股血气从顶门喷涌而出！\n" NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee",damage, me);
		me->receive_fulling("kee",damage/2, me);
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
