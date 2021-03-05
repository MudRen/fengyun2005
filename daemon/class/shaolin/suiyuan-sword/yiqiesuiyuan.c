// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod;
	object weapon;
	mapping buff;
	
	extra = me->query_skill("suiyuan-sword",1) ;
	if (extra <150) 
		return notify_fail("『一切随缘』需要１５０级的随缘无忧剑法。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『一切随缘』只能对战斗中的对手使用。\n");
		
	weapon = target->query_temp("weapon");

	mod = COMBAT_D->can_busy(me, target, "suiyuan-sword");    
    if (!mod)       mod = 1000;
	 
    if (COMBAT_D->do_busy_attack(me, target, "suiyuan-sword/yiqiesuiyuan", "step", 250, mod)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time()) {
    			
		message_vision(BBLU+HIY "\n使出一式『一切随缘』，剑身似灵蛇般缠住$n"BBLU HIY"手中的兵刃，"+ 
weapon->name()+  BBLU HIY"脱手而飞！\n" NOR, me,target);
		if(weapon->unequip()) {
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"随缘无忧剑法·一切随缘",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  60,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}
	} else	{
	        me->add_temp("apply/attack", extra*2);
	        me->add_temp("apply/damage", extra*2);
	msg = BBLU+ HIY+ "\n\n$N使出一式『一切随缘』，手中的"+(me->query_temp("weapon"))->name()+BBLU HIY"如闪电般直刺$n\n"+ NOR;
			message_vision(msg, me,target);
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	        me->add_temp("apply/attack", -extra*2);
	        me->add_temp("apply/damage", -extra*2);
	}
	
	target->set_temp("marks/disarmed",time());
	me->perform_busy(2);
	
	return 1;
}