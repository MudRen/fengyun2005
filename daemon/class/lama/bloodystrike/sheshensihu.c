// hippo@fengyun	2010.3.11

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration,x;
	mapping buff;
	
	if (me->query("class")!="lama") 
		return notify_fail("『舍身饲虎』是大昭寺的独门密技。\n");
		
	extra=me->query_skill("lamaism",1);
	if(extra<100)
		return notify_fail("『舍身饲虎』需要100级密宗佛法。\n");	


	extra=me->query_skill("bloodystrike",1);
	if(extra<100)
		return notify_fail("『舍身饲虎』需要100级密宗大手印。\n");	

	duration = me->query("timer/pfm/dz_sssh") - time() + 480;
    if( duration > 0 ) {
       	return notify_fail("你还需要等待"+(int)(duration+1)+"秒左右才能再次使用『舍身饲虎』。\n");
	}

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『舍身饲虎』只能对战斗中的对手使用。\n");
	
	if (ANNIE_D->check_buff(me,"ironup"))
		return notify_fail(me->name()+"『舍身饲虎』效果持续中。\n");
		
	mod = COMBAT_D->can_busy(me, target, "bloodystrike");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，无法得逞。\n"NOR);
	
	//lvl = 200;					
	lvl = (int) me->query_skill("unarmed") /40 + 1;
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIG"
$N使出一招『舍身饲虎』！一指快速的经过$n身上各处穴道。\n" NOR;
	message_vision(msg, me, target);
	if (COMBAT_D->do_busy_attack( me, target, "bloodystrike/sheshensihu","unarmed", lvl*100, mod))
	{
		msg = RED"$n大叫：上当了！回过神是已经晚了。\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 me,
			"type": "ironup",
			"att":  "bless",
			"name": "密宗大手印·舍身饲虎",
			"time":  120,
			"buff1": "apply/iron-cloth",
			"buff1_c": me->query_skill("jin-gang",1),
			"buff_msg": "",
			"disa_msg": "",
			//"condition_type":  "<身法迟钝>",
			"warn_msg":"",
//			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		if (target && !userp(target)) {
			x = me->query("combat_exp")> target->query("combat_exp") 
				? target->query("combat_exp"): me->query("combat_exp");
			target->add_hate(me, F_LEVEL->get_level(x)*30);
		}
	} else	{
			msg = WHT"$n：此等计量，岂能上当。\n"NOR;
			message_vision(msg,me,target);
	}
	me->set("timer/pfm/dz_sssh", time());
	me->perform_busy(1); 
	return 1;
}