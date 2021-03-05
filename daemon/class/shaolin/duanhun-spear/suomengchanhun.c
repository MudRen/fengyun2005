// Silencer@fengyun	June.2005
//	+atk 170, +dmg 340

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	object weapon;
	mapping buff;
			
	extra = me->query_skill("duanhun-spear",1) ;
	if ( extra < 150|| me->query_skill("spear",1)< 150) 
		return notify_fail("『锁梦缠魂』需要150级的断魂枪和150级的基本枪法。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『锁梦缠魂』只能对战斗中的对手使用。\n");
			
	weapon = target->query_temp("weapon");
	
	mod = COMBAT_D->can_busy(me, target, "duanhun-spear");    
    if (!mod)       mod = 1000;
	 
    if (COMBAT_D->do_busy_attack(me, target, "duanhun-spear/suomengchanhun", "step", 150, mod)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time()) {
    			
		message_vision(BBLU+HIY "\n$N使出一式『锁梦缠魂』，枪身似灵蛇般缠住$n手中的兵刃，"+ 
weapon->name()+  BBLU+HIY"脱手而飞！\n" NOR, me,target);
		if(weapon->unequip()) {
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"断魂枪·锁梦缠魂",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  30,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}
	} else	{
	        me->add_temp("apply/attack", extra);
	        me->add_temp("apply/damage", extra*2);
			msg = BBLU+ HIY+ "\n$N使出一式『锁梦缠魂』，手中的"
				HIY+ me->query_temp("weapon")->name()+ BBLU+HIY"如灵蛇般直咬$n！\n"+ NOR;
			message_vision(msg, me,target);
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	        me->add_temp("apply/attack", -extra);
	        me->add_temp("apply/damage", -extra*2);
	}
	
	target->set_temp("marks/disarmed",time());
	me->perform_busy(2);
	
	return 1;
}

