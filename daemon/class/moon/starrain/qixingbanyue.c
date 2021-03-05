
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,name;
		mapping buff;
		int extra,level, mod, count,amount,duration;
		object weapon;
		
		if (me->query("class") != "moon")
			return notify_fail("只有皓月宫的弟子才能施展『七星伴月』。\n");
	
		extra = me->query_skill("starrain",1);
		if (extra <100)
			return notify_fail("『七星伴月』需要至少100级的寒星雨觞。\n");
	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("『七星伴月』只能对战斗中的对手使用。\n");
			
		// We don't use mod since we want it to be workable on tough NPCs. but we need a timer to limit its repeatability.
		
		duration = me->query("timer/pfm/starrain_sp")+ 20 - time();	
		if (duration > 0)
			return notify_fail("『红藕香残』、『七星伴月』和『连天衰草』每２０秒钟只能使用一次（还需等待"+duration+"秒）\n");
		
		if (ANNIE_D->check_buff(target,"healshield"))
       		return notify_fail("对方已经受到了相似的影响。\n");
       				
		weapon = me->query_temp("weapon");
		count = weapon->query_amount();
		if (count < 7)
			return notify_fail("『七星伴月』至少需要7枚暗器。\n");
		
		name = weapon->name();
		if (userp(me))	weapon->add_amount(-7);
		
		me->set("timer/pfm/starrain_sp",time());
				
		msg = WHT"$N"NOR+WHT"一扬手，打出星星点点，星星四散，仿佛几缕销魂、几抹相思，但迅即转为杀气。\n";
		message_vision(msg,me,target);
		
		level = me->query("annie/starrain_qixingbanyue");
		if (me->query("class") != "moon")
			level = 0;
		if (!userp(me))
			level = 5;
		
		if (!level)					amount = 50;
		else if (level == 1)		amount = 70;
		else						amount = 90;
			
		amount = amount* (100 + F_ABILITY->check_ability(me,"yzhs_add")*5)/100;
		
		if (!COMBAT_D->do_busy_attack( me, target, "starrain/yanzihuishi","step", 200, 10))
		{
			msg = YEL "$N"NOR+YEL"大笑数声，"+ name+ NOR YEL"四散落地。\n"NOR;
			message_vision(msg,target);
		}
		else
		{
			msg = HIR+BLK"似有暗力牵引，"+name+HIR BLK"众星拱月般在$N"HIR BLK"身畔流动。\n"NOR;
			buff =
			([
				"caster":me,
				"who":target,
				"type":"healshield",
				"att":	"curse",
				"name":"寒星雨觞·七星伴月",
				"time":  10,
				"buff_msg":msg,
				"disa_msg":WHT"$N周围的"+name+ NOR WHT"余力已尽，散落而下。\n"NOR,
				"disa_type": 1,
				"shield_type":"kee",
				"shield_amount": amount,
				"shield_desc": HIR BLK"$n"HIR BLK"心头一颤，气血浮动不止。\n"NOR,								
			]);
			ANNIE_D->buffup(buff);	
		}

        return 1;
}
