// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
	int extra, exp_bonus;
	int mod;
	object weapon;
	
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("xuezhan-spear",1);
    	    	
    if (extra < 50 || me->query_skill("skyforce",1)<50)
    	return notify_fail("『乌龙摆尾』需要50级的血战枪法和碧空心法!\n");
    	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("『乌龙摆尾』只能对战斗中的对手使用。\n");
    
    mod = COMBAT_D->can_busy(me, target, "xuezhan-spear");	
	if (!mod)
		return notify_fail(HIW"此人功力深厚，不会被此招式迷惑的。\n"NOR);
	
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");

	msg = HIB"\n$N"HIB"手中的"+ weapon->name()+ HIB"忽然收回，枪尾一摆，从胁下穿出，如乌龙摆尾，连振三下，
但听得连续三声龙吟似的声响，枪影暴涨，\n"NOR;
	    			
    if (COMBAT_D->do_busy_attack( me, target, "xuezhan-spear/wulongbaiwei", "step", 230, mod))
    {
	    msg += YEL"$n如同遭到电击，全身刺痛，连退七步，这才稳住身子。\n"NOR;
		target->force_busy(2);
		target->set_temp("busy_timer/xuezhan-spear",time());
	}
	else{
	   	msg += WHT"$n"NOR+WHT"腾空跃起，一个翻身从$N"NOR+WHT"头上飞过！\n"NOR;
		me->perform_busy(1); 
	}
	
    message_vision(msg, me,target);
    return 1;
}



