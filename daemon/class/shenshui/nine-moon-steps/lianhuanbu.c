// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, n;
	
	if(userp(me) && me->query("class")!="shenshui")
		return notify_fail("只有神水弟子才能使用连环步。\n");
		
	extra = me->query_skill("nine-moon-steps",1);
	if ( extra < 30) return notify_fail("『连环步』需要３０级的九阴身法。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『连环步』只能对战斗中的对手使用。\n");
	
	mod = COMBAT_D->can_busy(me, target, "nine-moon-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	
	message_vision(HBRED+HIW"$N"HBRED+HIW"按着奇门八卦方位，脚踩连环，一闪一飘，绕圈踏出几步。\n"NOR,me,target);
	
	if ( me->query_temp("marks/pfm/ss_shui")|| !userp(me)) n = 80;
		else n = 50;
	
	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", n, mod))
	{
		message_vision(WHT"微风枫然，$N"NOR+WHT"已到了$n"NOR+WHT"身后，$n"NOR+WHT"真是进退两难，无法可施!\n\n"NOR,me, target);
		extra = extra > 150 ? 150 : extra; // Can't let it be 4+ turns busy.
		target->force_busy(2+random(extra/60));
		target->set_temp("busy_timer/nine-moon-steps",time());
	}
	else{
		message_vision(YEL"$n"NOR+YEL"施展绝顶轻功，俟的从干方绕到异位，$N"NOR+YEL"反被攻了个措手不及！\n\n"NOR,me, target);
		me->start_busy(1);
	}
	return 1;
}


