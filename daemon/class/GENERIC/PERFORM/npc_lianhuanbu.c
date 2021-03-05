// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int target_exp;

    	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");  
	
	extra = me->query_skill("nine-moon-steps",1);
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［连环步］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	
	message_vision(HIM"$N脚踩连环，环绕着$n转个不停！\n"NOR,me,target);
	if (target->query("possessed")) target_exp=target->query("combat_exp")/2;
		else target_exp=target->query("combat_exp");
		
	if(random(target_exp) < me->query("combat_exp")/2)
	{
		message_vision(YEL"        结果$N被扰得眼花潦乱，接应不暇！\n"NOR,target);
		target->start_busy(3);
	}
	else{
		message_vision(BLU"        结果$N自己转了个头晕眼花！\n"NOR,me);
		me->start_busy(1);
	}
	return 1;
}
