// silencer@fengyun 苍龙乍现 命中时，NPC, players 不能 pfm,

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, duration, kee, mod, enhance,cl;
	mapping buff;
		
	if (me->query("class")!="assassin")
		return notify_fail ("『苍龙乍现』只有金钱帮弟子能使用。\n");
	
	lvl= me->query_skill("jinhong-steps",1);
	if (lvl<80)
		return notify_fail("『苍龙乍现』需要至少80级金虹步法。\n");		
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『苍龙乍现』只能对战斗中的对手使用。\n");
	
	msg = HIR  "$N"+HIR"脚下一转，突然身形飞起，双脚如矫龙般腾空一卷，猛地向$n"+HIR"踢出！\n" NOR;
	message_vision(msg, me, target);
		
	if ((me->query_skill("jinhong-steps",1)>164 || !userp(me)) 
		&& random(201)>197
		&& !target->query("big_boss") && !target->query("boss") ) 
	{
		kee = target->query("kee");
		target->receive_wound("kee", kee/2, me);
		message_vision(RED"\n$n"+RED"一声惨叫，被$N"+RED"踢得狂喷鲜血。\n\n"NOR,me,target);
	}
	else
	{
		me->add_temp("apply/attack", lvl);	
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, "", "踢伤");
		me->add_temp("apply/attack", -lvl);		
	}		
	
	me->perform_busy(2);	
	mod = COMBAT_D->can_busy(me, target, "jinhong-steps");	
	if (!mod)	mod = 10000;
	
	cl=F_ABILITY->check_ability(me,"clzx_add");
     if(!cl){
     cl=1;
     }					
	// lvl = 160 *4 = 640	
	enhance = lvl* 4;
	if (COMBAT_D->do_busy_attack(me, target, "jinghong-steps/canglongzhaxian","step", enhance, mod))
	{
		msg=WHT"
$N大吼一声，身子在半空，双腿左右仰展，像风车一般，急施而起，
凌厉的腿风扫过，$n"WHT"胸闷气滞，真气逆转！\n"NOR;
		message_vision(msg, me, target);
		if (!ANNIE_D->check_buff( target, "lockup"))		
		{	
			buff =
			([
				"caster":me,
				"who":	 target,
				"type": "lockup",
				"att":  "curse",
				"name": "金虹步法·苍龙乍现",
				"time":  10 + random(5)+cl/5,
				"buff1": "till_death/lockup",
				"buff1_c": 1,
				"buff_msg": "",
				"warn_msg":"",
			]);
			ANNIE_D->buffup(buff);				
		}		
		target->set_temp("busy_timer/jinhong-steps",time());
	}
	
	return 1;
}