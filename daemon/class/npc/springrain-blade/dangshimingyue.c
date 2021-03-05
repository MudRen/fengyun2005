#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int extra;

 object weapon;

 extra = me->query_skill("springrain-blade",1);
 if ( extra < 120 && userp(me)) 
 	return notify_fail("你的春雨刀法不够纯熟。\n");
 if( !target ) target = offensive_target(me);
 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［当时明月］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIC  "$N轻叹一声，随手挽了个刀花，"+ weapon->name()+"斜斜挥出，却是『春雨刀法』中的精髓之式「当时－明－月－」！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC"		当   "HIY"	       曾\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		时   "HIY"	       照\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		明   "HIY"	       彩\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		月   "HIY"	       云\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC"		在   "HIY"	       归\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->perform_busy(3);
        me->add_temp("apply/attack",-extra*2);
        me->add_temp("apply/damage",-extra);
	return 1;
}
