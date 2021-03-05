
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl,extra, mod, x;
	
	if (userp(me))
	if (me->query("class")!= "lama")
		return notify_fail("『佛法无边』是大昭寺的独门密技。\n");
	
	extra=me->query_skill("bloodystrike",1);
	if(extra<20)
		return notify_fail("『佛法无边』需要20级密宗大手印。\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『佛法无边』只能对战斗中的对手使用。\n");
	
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");	
		
	mod = COMBAT_D->can_busy(me, target, "bloodystrike");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此手法迷惑的。\n"NOR);

//	170/2+1.1*200 = 305, 305/40 +1 = 8	
	
	lvl = (int) me->query_skill("unarmed") /40 + 1;
		
	msg = HBRED+HIW "$N"HBRED+HIW"使出密宗大手印中的『佛法无边』，幻出无数掌影击向$n！" NOR;
	
	if (COMBAT_D->do_busy_attack(me, target, "fofawubian", "unarmed", lvl* 100, mod))
	{
		message_vision(msg + "\n", me, target);
		msg = YEL"结果$n"NOR+YEL"被$N"NOR+YEL"攻了个手忙脚乱！\n"NOR;
		message_vision(msg, me, target);
		target->set_temp("busy_timer/bloodystrike",time());
		target->force_busy(3);
	}
	else
	{
		me->add_temp("apply/attack",extra/3);	
	        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra/3);	
	}
	me->perform_busy(2);
	
	// INherently, Every busy has 4*level hate, unarmed makes it 10x you/target level every 2 turn.
	if (target && !userp(target)){
		x = me->query("combat_exp")> target->query("combat_exp") 
			? target->query("combat_exp"): me->query("combat_exp");
		target->add_hate(me, F_LEVEL->get_level(x)*6);
	}
	
	return 1;
}
