// Silencer @ FY4 workgroup. Feb.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int skill, atk, lmt, j, i,duration;
		string *perform_msg = ({
			WHT"	腥风\n"NOR,
			HIR"		血雨\n"NOR,
			WHT"			刀断刃\n"NOR,
			HIR"				人断肠\n"NOR,
			WHT"			绝	\n"NOR,
			HIR"  		灭	\n"NOR,

		});

		skill = me->query_skill("wolf-strike",1);
    	if( skill < 150 || me->query_skill("summonwolf",1)< 150) 
			return notify_fail(" 『残肢』需要150级的天狼百破拳和唤狼术！\n");

    	// duration = 90sec.
		duration = me->query("timer/pfm/wm_canzhi")+ 90 -time();
		if (duration>0)
    		return notify_fail("『残肢』需要"+chinese_number(duration)+"秒后才能再次运用。\n");
    	
    	if( !target ) target = offensive_target(me);
    	if( !target
      		||      !target->is_character()
      		||      !me->is_fighting(target) )
			return notify_fail("『残肢』只能对战斗中的对手使用。\n");

		lmt = 6;
    	atk = skill;	// +200；
    		 
    	message_vision(HIB"\n
$N招式一变，阴柔奇诡，狠毒异常，十指有如十柄利剑，刹那之间便已攻出数招！！\n"NOR, me);
		    	
    	me->add_temp("apply/attack", atk);
    	
    	for(i=1;i<=lmt;i++)
    	{
	    	msg =  perform_msg[i-1];
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);					
//			if (!target->query_temp("damaged_during_attack")) break;
			if (me->is_busy())		break;
    	}

    	me->add_temp("apply/attack",-atk);
    	me->set("timer/pfm/wm_canzhi", time());  	    	
    	me->perform_busy(1);

        return 1;
}

