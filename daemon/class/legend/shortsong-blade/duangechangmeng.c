// tie@fengyun
//食芝英，饮醴泉，柱杖桂枝佩秋兰。
//绝人事，游浑元，若疾风游［炎欠］翩翩。
//景未移，行数千，寿如南山不忘愆。

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
	int extra,i, apply, n;
	int chance;
	object weapon;
	extra = me->query_skill("shortsong-blade",1);
	if ( extra < 30) return notify_fail("『短歌长梦』需要30级的短歌刀法！\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
		return notify_fail("『短歌长梦』需要棋道心法的配合！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『短歌长梦』只能对战斗中的对手使用。\n");
	
	weapon = me->query_temp("weapon");
	
	target->set_temp("no_check_pfm_win",1);
	
	n =2;
	chance = 10;
	chance = chance + me->query_temp("pfm/legend_berserk");
	
	if (me->query("timer/pfm/legend_3hit")+ 60 < time())
		chance = 100;

//	CHANNEL_D->do_sys_channel("sys", "chance is "+ chance + "\n");
	
	if (me->query("class")!="legend") {
		msg = HIY "$N使出短歌刀法中的『短歌长梦』，一招连环两式，手中的"+ weapon->name()+  HIY"闪电般向$n"HIY"攻出第一刀！”" NOR;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	        target->set_temp("skip_damage_record",1);
	        
	        msg = HIY  "第二刀！" NOR;
	        me->add_temp("apply/damage",extra);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	        me->add_temp("apply/damage",-extra);
		
		if (extra >= 200 && chance > random(100)) {
			me->add_temp("apply/damage",extra);
	        	msg = HIY  "$N更不放松，竟又挥出第三刀！" NOR;
	        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-extra);
			me->set("timer/pfm/legend_3hit",time());
		} 
	} 
	else 
	{
		me->add_temp("apply/damage",extra);
		msg = HIY  "\n$N使出短歌刀法中的『短歌长梦』，一招连环两式，
手中的"+ weapon->name()+ HIY "闪电般向$n"HIY"攻出第一刀！“食芝英，饮醴泉，柱杖桂枝佩秋兰”\n" NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->set_temp("skip_damage_record",1);

       	msg = HIY  "\n第二刀！“绝人事，游浑元，若疾风游赕翩翩”\n" NOR;
       	message_vision(msg,me,target);
       	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
 		me->add_temp("apply/damage",-extra);        	
	
		if (extra >=200 && chance > random(100)) {	
			apply = extra;
			me->add_temp("apply/damage",apply);
			msg = HIY  "\n$N更不放松，竟又挥出第三刀！“景未移，行数千，寿如南山不忘愆”\n" NOR;
        	message_vision(msg, me, target);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
			me->add_temp("apply/damage",-apply);	
			me->set("timer/pfm/legend_3hit",time());
		}
	}
	
		if (objectp(target)){
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
			
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

			       
	me->perform_busy(n);
	return 1;
	
}
       	