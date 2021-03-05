// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("zhao-sword",1);
	if ( extra < 70) return notify_fail("你的五展梅剑法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［梅开五度］只能对战斗中的对手使用。\n");
	msg = CYN "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n第一剑！梅花初绽！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "第二剑！梅开二度！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "第三剑！朵朵寒梅！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	msg = CYN  "第四剑！嘘寒问暖！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "第五剑！梅花消逝！"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->start_busy(2);
	return 1;
}
