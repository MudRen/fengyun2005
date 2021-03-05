#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, dmg, mod, duration;
	mapping buff;
	
    if(me->query("class")!="wolfmount")
    	return notify_fail("只有狼山弟子才能使出『凝血』的绝技。\n");
    	
	extra = me->query_skill("wolf-strike",1) ;
	if(extra < 200 || me->query_skill("summonwolf",1)<200 ) 
		return notify_fail("『凝血』需要200级的天狼百破拳和唤狼术！\n");
	
	duration = me->query("timer/pfm/wm_ningxue")+ 90 -time();
	if (duration>0)
		return notify_fail("『凝血』极耗元气，需要"+duration+"秒钟后才能再次运用。\n");
    		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(WHT"『凝血』只能对战斗中的对手使用。\n"NOR);

	msg = WHT "$N"WHT"双爪回环各划一个弧形，一股森森的阴风直扑$n。\n" NOR;
	
	// atk 200*3
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra*3);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
    me->add_temp("apply/attack",-extra*3);
        	    	
	me->perform_busy(1);
	
	if (!target || !target->query_temp("damaged_during_attack"))
		return 1;
    
    if (ANNIE_D->check_buff(me, "wolf-berserk"))
    	return 1;
    			
    msg = HIR"$N一抓得手，十指鲜血淋漓，眼神愈发狂热，喉中发出慑人的低吼声。\n"NOR;    
    buff =
			([
				"caster": me,
				"who":    me,
				"type": "wolf-berserk",
				"att":	"bless",
				"name":	"天狼百破·凝血",
				"buff1":  "apply/parry",
				"buff1_c":100,
				"buff2":  "apply/attack",
				"buff2_c": 100,
				"buff3":  "apply/dodge",
				"buff3_c": 100,			
				"time":  40 ,
				"buff_msg": msg,
	]);
			
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/wm_ningxue",time());
	   	
    return 1;
}
