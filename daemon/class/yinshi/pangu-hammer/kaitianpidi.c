// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	if(userp(me))
		return notify_fail("只有蓝大弟子才能使『开天辟地』\n");
	
	if (me->query_skill("pangu-hammer",1)<100)
		return notify_fail("『开天辟地』需要100级的盘古锤法。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『开天辟地』只能对战斗中的对手使用。\n");
	
	weapon = me->query_temp("weapon");
	extra = me->query("force");
	if ( extra < 300) return notify_fail("你的内力太弱，运用不出『开天辟地』这绝招！\n");
		
	msg = HIC"
	        ☆ 开 ☆ 天 ★ 辟 ☆ 地 ☆\n\n"NOR;
	msg += HIY  "    $N"+HIY"高高地举起手中的"+ weapon->name()+ HIY"集全身之内力，向$n"+HIY"猛然砸下\n\n" NOR;
	message_vision(msg, me, target);
	
	me->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/damage", -extra);
	
	if (userp(me)) me->set("force",(me->query("force"))*2/3);
	me->perform_busy(3);
	return 1;
}

