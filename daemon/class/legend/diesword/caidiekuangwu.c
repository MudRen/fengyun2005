// Silencer@fengyun	June.2005
//	inherent +20% from six-sense
// no +atk, +dmg, 1st 100, 2nd 100, 3rd 500+200
//	compared to FY4 1st 150, 2nd 150, 3rd 1100

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,apply, dmg, n;
	object weapon;
	
	int chance;
	
	extra = me->query_skill("diesword",1);
	weapon=me->query_temp("weapon");
	if ( extra < 30) 
		return notify_fail("『彩蝶狂舞』需要30级蝶恋花剑法！\n");

	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("『彩蝶狂舞』需要棋道心法的配合！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『彩蝶狂舞』只能对战斗中的对手使用。\n");
	
	n =2;
	chance = 10;
	chance = chance + me->query_temp("pfm/legend_berserk");
	
	if (me->query("timer/pfm/legend_3hit")+ 60 < time())
		chance = 100;
			
//	CHANNEL_D->do_sys_channel("sys", "chance is "+ chance + "\n");
	target->set_temp("no_check_pfm_win",1);
	if (me->query("class")!="legend") {
		msg = HIG  "$N使出蝶恋花剑法中的『彩蝶狂舞』，一招连环两剑，
手中的"+ weapon->name()+  HIG"闪电般向$n"HIG"攻出第一剑！" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		target->set_temp("skip_damage_record",1);
		
		msg = HIG  "第二剑！" NOR;
	        me->add_temp("apply/damage",extra);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	        me->add_temp("apply/damage",-extra);
			
		if (extra>=200 && chance > random(100)) {
			me->add_temp("apply/damage",extra);
	        	msg = HIG  "$N剑尖急抖，一片剑影中又攻出第三剑！" NOR;
	        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-extra);
			me->set("timer/pfm/legend_3hit",time());
		} 
	}
	else	
	{
		me->add_temp("apply/damage",extra);
		msg = HIG  "\n$N使出蝶恋花剑法中的『彩蝶狂舞』，一招连环两剑，
手中的"+ weapon->name()+  HIG"闪电般向$n"HIG"攻出第一剑！“心如镜，肩上细蝶飞”\n" NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        	target->set_temp("skip_damage_record",1);
        	
        	msg = HIG  "\n第二剑！“应趁无风投比翼, 待得愁落去人回”\n" NOR;
        	message_vision(msg, me, target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
 		me->add_temp("apply/damage",-extra);        	
	
		if (extra >=200 && chance > random(100)) {
			// 200 + 150 + 150 = 500
			apply = extra;
			me->add_temp("apply/damage",apply);
			msg = HIG  "\n$N剑尖急抖，一片剑影中又攻出第三剑！“波乱影难归”\n" NOR;
        	message_vision(msg, me, target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
			me->add_temp("apply/damage",-apply);
			me->set("timer/pfm/legend_3hit",time());
		}
	}
	
		if (objectp(target)){
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
	//		else 
	//			me->set_temp("pfm/caidiekuangwu_miss",time());
			
			me->delete_temp("pfm/tx-hit-dodged");
			me->delete_temp("pfm/tx-hit-parried");
			if (target->query_temp("marks/parried"))
				me->set_temp("pfm/tx-hit-parried",time());
			else if (target->query_temp("marks/dodged"))
				me->set_temp("pfm/tx-hit-dodged",time());
			
			if (wizardp(me))
				tell_object(me, "target dodged = " + target->query_temp("marks/dodged") 
					+ ", target parried = "+target->query_temp("marks/parried") + "\n");
		
		}
				
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

/*		if (extra >=200 && me->query_skill("six-sense",1)>=250
			&& me->query_temp("pfm/legend_berserk") && random(2)) {
			n = n - 1;
		}*/
        me->perform_busy(n);
		return 1;
	
}