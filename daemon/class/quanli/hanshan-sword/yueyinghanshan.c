// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("hanshan-sword",1);
	if ( extra < 40) return notify_fail("你的［寒山十八式］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［月映寒山］只能对战斗中的对手使用。\n");
	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*4);

	weapon = me->query_temp("weapon");
	msg = HIR  "$N使出寒山十八式中的最后一式----［月映寒山］，手中的"+ weapon->name()+ HIR "直刺$n的双眉！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIR  "只见$N手上又多出一把"+ weapon->name()+ HIR"闪电般地划向$n的左肩！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra*4);
	me->start_busy(2);
	return 1;
}
