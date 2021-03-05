// Silencer/Sinny@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	int exp_bonus;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『丧乱』只能对战斗中的对手使用。\n");
	
	extra = me->query_skill("calligraphy",1);
	
	if (extra < 40)
		return notify_fail("『丧乱』需要40级的书法。\n");
		
	exp_bonus=(me->query("combat_exp")-3000000)/1000*extra/6000;
	if (exp_bonus<0) exp_bonus=0;	
		
	me->add_temp("apply/attack", extra + exp_bonus);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$N如疯如癫、如酒醉、如中邪，笔意淋漓直扫$n，指走龙蛇之间
正是丧乱帖中『丧乱之极』的四字菁华！\n" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra - exp_bonus);
	me->add_temp("apply/damage", -extra*2);
	
	me->perform_busy(2);
	return 1;
}
