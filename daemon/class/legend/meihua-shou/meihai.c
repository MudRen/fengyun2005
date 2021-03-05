#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra, mod,x;
	
	if (userp(me))
	if (me->query("class")!= "legend")
		return notify_fail("『梅海』是铁雪山庄的独门武功。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『梅海』只能对战斗中的对手使用。\n");
	
	extra= (int)me->query_skill("meihua-shou",1);
	
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
		
	mod = COMBAT_D->can_busy(me, target, "meihua-shou");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此掌法迷惑的。\n"NOR);
				
	//   160/2 + 1.5x150 = 305/30+1= 11 	
	lvl = (int) me->query_skill("unarmed") / 30 + 1;
	
	if (me->query_temp("pfm/legend_berserk"))
		lvl = lvl /2;
	
	msg = BRED + HIW "$N" BRED+HIW"双手幻出漫天梅花，飞雪似的向$n"BRED+HIW"落来！\n" NOR;
		
	if (COMBAT_D->do_busy_attack(me, target, "meihua-shou", "unarmed", lvl* 100, mod))
	{
		msg += WHT"结果$n被$N攻了个手忙脚乱！\n"NOR;
		message_vision(msg, me, target);
		target->force_busy(3);
		target->set_temp("busy_timer/meihua-shou",time());
		me->perform_busy(2);
	} else
	{	
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->perform_busy(2);
	}
	
	// INherently, Every busy has 4*level hate, unarmed makes it 10x you/target level every 2 turn.
	if (target && !userp(target)){
		x = me->query("combat_exp")> target->query("combat_exp") 
			? target->query("combat_exp"): me->query("combat_exp");
		target->add_hate(me, F_LEVEL->get_level(x)*6);
	}
	return 1;
}


