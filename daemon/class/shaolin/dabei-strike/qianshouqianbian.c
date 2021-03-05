#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra, mod, x;

	if (userp(me))
	if (me->query("class")!= "shaolin" && me->query("class")!="bonze")
		return notify_fail("『千手千变』是佛门武功。\n");
	
	extra=me->query_skill("dabei-strike",1);		
	if(extra<20)
		return notify_fail("『千手千变』需要20级的大慈大悲千叶式。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『千手千变』只能对战斗中的对手使用。\n");
		
	if ((target->query("boss") || target->query("big_boss"))&& me->query("class")!="shaolin")
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
		
	mod = COMBAT_D->can_busy(me, target, "dabei-strike");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);
			
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
			
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp")* mod/10;

// 	(180/2+1.2x180)	= 306/40+1 = 8
	lvl = (int) me->query_skill("unarmed") / 40 + 1;

	// 兴国的BUSY效率不高
	if (lvl > 5 && me->query("class")=="bonze")	lvl = 5;
			
	msg = HBRED+HIW "$N"HIW"使出大悲千叶掌法中的『千手千变』，幻出无数掌影击向$n！" NOR;
			
	if (COMBAT_D->do_busy_attack(me, target, "dabei-strike", "unarmed", lvl* 100, mod)) 
	{
		message_vision(msg + "\n", me, target);
		msg = YEL"结果$n被$N攻了个手忙脚乱！\n"NOR;
		message_vision(msg, me, target);
		target->force_busy(2);
		target->set_temp("busy_timer/dabei-strike",time());
		me->perform_busy(1);
	}
	else
	{
		me->add_temp("apply/attack",extra/2);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra/2);
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



