// silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int hit_break(object target, object me, int factor);

int perform(object me, object target)
{
	string msg;
	int extra, skill, duration;
   	if( me->query("class") != "shenshui" ) {
    	return notify_fail("只有神水宫弟子才能使出『破颅』的绝技。\n");
    }
    if( userp(me) ) {		
		if( me->query_skill("nine-moon-claw", 1) < 150 || me->query_skill("nine-moon-steps", 1) < 150 || me->query_skill("nine-moon-force", 1) < 150 || me->query_skill("nine-moon-spirit", 1) < 150 ) {
			return notify_fail("『破颅』需要150级九阴白骨爪，150级九阴身法，九阴心经和姹女神功。\n");
		}
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『破颅』只能对战斗中的对手使用。\n");
	}

	skill = me->query_skill("nine-moon-claw", 1);
	if( !userp(me) ) {
		duration = (skill> 200) ? 0 : (200 - skill);
		duration = me->query_temp("timer/pfm/polu") + duration - time();
	} else {
		duration = time() - target->query_temp("marks/pfm/polu_chance") - 8;
	}		
	// 2.7M 900	
	// 6.4M 200*2 + 180 + 180 + 200*2 + 103 *3 = 1469
	// full 200*2  +180 + 180 + 200*2 + 140 *3 = 1580
	extra = me->query_skill("nine-moon-claw",1)*2 + me->query_skill("nine-moon-steps",1)
			+ me->query_skill("nine-moon-force",1) + me->query_skill("nine-moon-spirit",1)*2
			+ F_LEVEL->get_level(me->query("combat_exp"))*3;
			
	// + atk 240 -> 308, dmg 240 -> 308, a normal one-hit perform.	
	me->add_temp("apply/attack", extra/7);	
	me->add_temp("apply/damage", extra/5);
	msg = HIW"$N"HIW"身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n"HIW"身边，
袖中伸出纤纤素手，五根手指疾抓$n"HIW"$l。\n"NOR ;
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -extra/7);
	me->add_temp("apply/damage", -extra/5);
                                
	// for NPC, every 40 sec (L160)-- 0 sec (L200+) can pfm 2nd hit.
	// For players, it's decided by chillbreath and shuanglengcanxia
	if( duration < 0 ) {
		message_vision(HIW"\n$N"+HIW"更不稍停，反掌间五根手指已向$n"HIW"的头顶插了下去。\n"NOR, me, target);
		target->delete_temp("marks/pfm/polu_chance");
	    hit_break(target, me, extra);
	}
	me->perform_busy(2);  
	return 1;
}

int hit_break(object target, object me, int factor)
{
	int damage;
	// High hit rate, 不受 boss 等 busy rate 影响
	if( COMBAT_D->do_busy_attack(me, target, "nine-moon-claw", "unarmed", 800, 10) ) {
		message_vision(MAG"$N"MAG"惨叫一声，顶门已被$n"NOR+MAG"的手掌罩住！\n"NOR, target, me);
		// 900 -1540
		damage = COMBAT_D->magic_modifier(me, target, "kee", factor);
		damage = damage*(100+F_ABILITY->check_ability(me,"3_polu_add",3)*3)/100;
		target->receive_damage("kee", damage, me);
		COMBAT_D->report_status(target);
        COMBAT_D->win_lose_check(me, target, damage);
	} else {	
		message_vision(YEL"$N"NOR+YEL"不慌不忙，抢前半步，避开了脑门要害。\n"NOR, target);
	}
	if( !userp(me) ) {
		me->set("timer/pfm/polu", time());
	}
	return 1;
}
