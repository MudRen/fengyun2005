// tanzhijinghun.c
//	Busy Rate= *4 unarmed 

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) {
	
	string msg;
	int skill, mod, enhance, damage;
	
	if (me->query("class")!="huashan")
		return notify_fail("『弹指惊魂』是华山绝技。\n");
	
	skill = (int) me->query_skill("tanzhi-shentong",1); 	
    if ( skill <80) 
    	return notify_fail("『弹指惊魂』需要80级的弹指神通！\n");
	
	if( !target ) target = offensive_target(me);
	if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
		return notify_fail("『弹指惊魂』只能对战斗中的对手使用。\n");
	}
	
	if(target->is_busy()) {
		return notify_fail("对方已经不能动弹了。。。\n");
	}
	
	mod = COMBAT_D->can_busy(me, target, "tanzhi-shentong");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
		
		
	msg = HIG"$N"+HIG"身影如旋风般舞动，指风破空之声嗤嗤不绝袭向"+"$n"+HIG"各处要穴。\n"NOR;
	
	enhance = 400;
	
	if (COMBAT_D->do_busy_attack(me, target, "tanzhi-shentong/tanzhijinghun","unarmed", enhance, mod))
	{
		msg += HIG"$n"+HIG"只觉胸口膻中穴一麻，登时动弹不得。\n" NOR;		
		//	200
		damage = me->query_skill("throwing",1)/5;
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee", damage, me);
		target->force_busy(3);
		if(me->query_skill_mapped("force") != "hanmei-force") {
			me->perform_busy(2);
		}
		else {
		   	msg += WHT"$N"+WHT"内力流转，身法居然少见滞涩！\n\n"NOR;
		   	me->perform_busy(1);
		}
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
		target->set_temp("busy_timer/tanzhi-shentong",time());
	} else {
		msg += YEL"$n"+YEL"就地一滚堪堪躲过了$P"+YEL"的指风！！\n"NOR;
		message_vision(msg, me, target);
		me->perform_busy(2);
	}
	
	return 1;
}

