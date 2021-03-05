// 幻影千重
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,n, myexp, mod;
	
	extra = me->query_skill("meng-steps",1);
	if ( extra < 100) return notify_fail("需要100级幻梦步法才能使用『幻影千重』\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『幻影千重』只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
		
	if (me->query("class")=="bat" && extra >=170) n=0;
		else n=10;
	if(me->query_temp("huanyinqianchong")+n>time() && userp(me))
		return notify_fail("你刚刚施展过『幻影千重』\n");	
	
	mod = COMBAT_D->can_busy(me, target, "meng-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
/*	myexp=random(me->query("combat_exp")*3);
	if (me->query("class")=="bat")
		myexp=myexp+me->query("combat_exp")/5;*/
		
	message_vision(HIR"\n$N"+HIR"的身影突然一变十、十变百、百变千，"+HIR"$n"+HIR"早被"+HIR"$N"+HIR"的千重幻影围住！\n\n" NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "meng-steps/huanyinqianchong", "step", 200, mod))
	{
		message_vision(HIW "结果"+HIW"$N"+HIW"目眩神弛，心惊肉跳！\n\n" NOR,target);
		target->force_busy(3);
		me->set_temp("huanyinqianchong",time());
		target->set_temp("busy_timer/meng-steps",time());
	}
	else{
		message_vision(YEL"但是"+YEL"$N"+YEL"并不被幻影所扰乱！\n\n"NOR,target);
		me->perform_busy(2);
	}
	
	return 1;
}
