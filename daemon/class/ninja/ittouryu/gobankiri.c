// mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,weapon_name;
	int extra, mod;
	object weapon,myweapon;
	mapping buff;

	extra = me->query_skill("ittouryu",1) ;
	if ( extra < 100) 
		return notify_fail("『棋盘切』需要１００级的『一刀流剑术』！\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『棋盘切』只能对战斗中的对手使用。\n");
	
	weapon = target->query_temp("weapon");
	myweapon = me->query_temp("weapon");
	weapon_name= myweapon->query("name");
	
	mod = COMBAT_D->can_busy(me, target, "ittouryu");    
    if (!mod)       mod = 1000;
    
    message_vision(HIG "$N根本无视$n的攻击，大吼一声『棋盘切』！将"+weapon_name+ HIG"高举过肩，
自右上方直向$n劈去。\n"NOR,me, target);
	
 	if (COMBAT_D->do_busy_attack(me, target, "ittouryu/gobankiri", "step", 150, mod)
    	&& weapon && !weapon->query("nodrop_weapon")
    	&& target->query_temp("marks/disarmed") + 60 < time()) {    
    	message_vision(HIG"
面对$N雷霆一般的一击，$n用手中的兵器下意识地一挡。
"+ HIW"
$n只觉得虎口一热，手中的"+weapon->name()+HIW"再也拿不住了，“当”地一声掉了下来。\n\n" NOR, me,target);
		if(weapon->unequip()) {
			buff =
				([
					"caster":me,
					"who":  target,
					"type":"disarmed",
					"att":"curse",
					"name":"一刀流剑术·棋盘切",
					"buff1":"disarmed",
					"buff1_c":1,
					"time":  30,
					"buff_msg":" ",			
				]);
			ANNIE_D->buffup(buff);
		}
	}
	else {
		if (!random(10) && !target->query_temp("damaged_during_attack") && target->query_temp("weapon")
			&& COMBAT_D->do_busy_attack(me, target, "ittouryu/gobankiri", "step", 100, mod))
		{
			msg = "面对$N雷霆一般的一击，$n用手中的兵器下意识地一挡。"+
HIC"\n只听得“当”地一声大响，两人手中的兵器一震，各自后退了一步。\n\n"+ NOR;
			message_vision(msg,me,target);
			target->set_temp("busy_timer/ittouryu",time());
			target->force_busy(2);
		} else {
			me->add_temp("apply/attack",extra);
			me->add_temp("apply/damage",extra*2);
			COMBAT_D->do_attack(me,target,1,"");
			me->add_temp("apply/attack",-extra);
			me->add_temp("apply/damage",-extra*2);
		}
	}
    target->set_temp("marks/disarmed",time());	
	me->perform_busy(2);
	return 1;
}
