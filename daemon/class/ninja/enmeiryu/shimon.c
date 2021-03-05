// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
		
	if(me->query_skill("enmeiryu",1)<120)
		return notify_fail("四门-朱雀需要120级的陆奥圆明流拳术。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『四门-朱雀』只能对战斗中的对手使用。\n");
		
	if(me->query("kee")*100/me->query("max_kee")> 20 || me->query("kee")>1000)
		return notify_fail("『四门-朱雀』只能在气血值低于1000（20%）时使用。\n");
	
	extra = me->query_skill("unarmed") ;
		
	msg = HIR "$N口中喃喃说道：“只有那一招了。”，绝望中$N使出了最后的一招『四门.朱雀』!
$n一时以为自己眼花，居然看到四个$N的身影!
$n身后的一个$N猛地冲向$n，用膝部顶住$n的腰，单手揪住$n
的头，用力向地面磕去，同时肘部击向$n的眉心。" NOR;
        
// damage =(372-150)*10 = 2220, atk = 222*4;
    extra=extra-150;
	
	me->add_temp("apply/damage",extra*10);
	me->add_temp("apply/attack",extra*4);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*10);
    me->add_temp("apply/attack",-extra*4);
	
	target->add_hate(me, extra*10);	// !!
		
	me->perform_busy(2);
	return 1;
}
