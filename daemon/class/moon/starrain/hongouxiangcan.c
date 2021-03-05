#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg;
		mapping buff;
		int extra,level, mod, count, duration;
		object weapon;
		
		if (me->query("class") != "moon")
			return notify_fail("只有皓月宫的弟子才能施展『红藕香残』。\n");
	
		extra = me->query_skill("starrain",1);
		if (extra <130)
			return notify_fail("『红藕香残』需要至少130级的寒星雨觞。\n");
	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『红藕香残』只能对战斗中的对手使用。\n");
		
		duration = me->query("timer/pfm/starrain_sp")+ 20 - time();	
		if (duration > 0)
			return notify_fail("『红藕香残』、『七星伴月』和『连天衰草』每２０秒钟只能使用一次（还需等待"+duration+"秒）\n");
			
		if (ANNIE_D->check_buff(target,"fight_stop"))
       		return notify_fail("对方已经受到了相似的影响。\n");

		// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
				
		weapon = me->query_temp("weapon");
		count = weapon->query_amount();
		if (count < 6)
			return notify_fail("『红藕香残』至少需要6枚暗器。\n");
		if (userp(me))	weapon->add_amount(-6);
		
		me->set("timer/pfm/starrain_sp",time());
		
		msg = HIR "\n$N凌空翻身，右手紧执左手，左掌中、食、无名三指并伸，转眼间左手通体血红，哧的一声，一道红芒如赭，破指而出。\n"NOR;
		message_vision(msg,me,target);

		if (!COMBAT_D->do_busy_attack( me, target, "starrain/hongouxiangcan","step", 200, 10))
		{
			msg = YEL "$N"NOR+YEL"身形陡然倒飞，险险地避开了红芒。\n"NOR;
			message_vision(msg,target);
		}
		else
		{
	    	msg = HIR BLK"$N浑身剧震，踉跄倒退，鲜血自唇角涌出。\n\n" NOR;
			buff =
			([
				"caster":me,
				"who":target,
				"type":"fight_stop",
				"att":	"curse",
				"name":"寒星雨觞·红藕香残",
				"time":  5,
				"buff1": "marks/fight_stop",
				"buff1_c":	1,	
				"buff_msg":msg,
				"disa_msg":WHT"$N的痛楚终于渐渐消散。\n"NOR,
				"disa_type": 1,
			]);
			ANNIE_D->buffup(buff);	
		}

        return 1;
}
