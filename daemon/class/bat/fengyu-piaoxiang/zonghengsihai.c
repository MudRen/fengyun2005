// 纵横四海      
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod, enhance;
	extra = me->query_skill("fengyu-piaoxiang",1);
	if ( extra < 150) return notify_fail("『纵横四海』需要150级风雨飘香步。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『纵横四海』只能对战斗中的对手使用。\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
		
	mod = COMBAT_D->can_busy(me, target, "fengyu-piaoxiang");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
	
	message_vision(HIY"$N身形突然加快，如同天助，潇洒倜倘又有纵横四海之气势！\n" NOR,me,target);
	
	enhance = 150 + (extra -150)/2;
	
	if (COMBAT_D->do_busy_attack( me, target, "fengyu-piaoxiang/zonghengsihai", 
		"step", enhance, mod))
	{
		message_vision(HIB "结果$N"+HIB"缚手缚脚，一筹莫展！\n" NOR,target);
		me->set_temp("timer/pfm/zonghengsihai",time());
		target->force_busy(2+random(2));
		target->set_temp("busy_timer/fengyu-piaoxiang",time());
	}
	else{
		message_vision(YEL"结果$N并不慌乱！\n"NOR,target);
		me->perform_busy(2);
	}
	return 1;
}


