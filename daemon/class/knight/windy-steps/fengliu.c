#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int extra,enhance,mod;
	
	if (userp(me))
		return notify_fail("没有这项武功特技。\n");
		
	extra = me->query_skill("windy-steps",1);
	if ( extra < 50) 
		return notify_fail("『风流』需要50级急风三十六式。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『风流』只能对战斗中的对手使用。\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	
	mod = COMBAT_D->can_busy(me, target, "windy-steps");	
	if (!mod)
		return notify_fail(HIW"此人身势灵活，功力深湛，不会被此步法迷惑的。\n"NOR);
	
	message_vision(HIY"$N"HIY"脚踩风流步，衣襟飘飘，仿佛风卷残云，环绕着$n"HIY"陀螺般愈转愈快！\n"NOR,me,target);
	
	if (me->query("class") == "knight")	type = "step";
		else 				type = "unarmed";
	
	enhance = 150 + extra/2;
	
	if (COMBAT_D->do_busy_attack(me, target, "windy-steps/fengliu", type, enhance, mod))
	{			
		message_vision(HIG"结果$N"HIG"被扰得眼花潦乱，接应不暇！\n"NOR,target);
		target->set_temp("busy_timer/windy-steps",time());
		target->force_busy(2+random(2));
	}
	else{
		message_vision(WHT"结果$N"WHT"自己转了个头晕眼花！\n"NOR,me);
		me->perform_busy(2);
	}
	return 1;
}