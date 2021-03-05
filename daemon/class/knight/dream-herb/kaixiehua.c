// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int skill, enhance, mod;
    	string msg;

    	if(me->query("class")!="knight")
    		return notify_fail("只有快活林弟子才能够使用『开谢花』\n");

	skill = me->query_skill("dream-herb",1);
	if (skill <50)
		return notify_fail("『开谢花』需要50级的云梦五花锦。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『开谢花』只能对战斗中的对手使用。\n");
		
	if (target->is_busy())
		return notify_fail("对手已经在忙乱中了。\n");
		
	mod = COMBAT_D->can_busy(me, target, "dream-herb");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被毒倒的。\n"NOR);
		
	message_vision(HIM"\n但听得“波”的一声，突然从$N手上飞出一团烟雾，烟雾中有无
数细若游丝的光芒，而且发出嗤嗤的声响。\n"NOR, me, target);

	enhance = 200 + skill /2;	// 200 + 100 = 300
	
	if (COMBAT_D->do_busy_attack(me, target, "dream-herb/kaixiehua", "step", enhance, mod))
	{			
		message_vision(HIG"轰响声中，一团浓烟烈焰，已在$N的身边炸开。\n"NOR,target);
		target->set_temp("busy_timer/dream-herb",time());
		target->force_busy(2+random(2));
	}
	else{
		message_vision(YEL"$N"YEL"不慌不忙，一掌将烟雾击散！\n"NOR,target);
		me->perform_busy(2);
	}
	
	return 1;
	
}
	