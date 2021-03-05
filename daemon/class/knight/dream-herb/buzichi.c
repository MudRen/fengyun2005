// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *team, *team1;
   	int i, skill, enhance, num, amount, duration;
   	string msg;
   	mapping buff;

   	if(me->query("class")!="knight")
   		return notify_fail("只有快活林弟子才能够使用『不自持』\n");

	skill = me->query_skill("dream-herb",1);
	if (skill <200 || me->query_skill("herb",1)< 240)
		return notify_fail("『不自持』需要200级的云梦五花锦和240级基本药道。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『不自持』只能对战斗中的对手使用。\n");
		
	duration = me->query("timer/pfm/khl_buzichi")-time() + 20;
    if (duration>0)
       	return notify_fail("你还需要等待"+(duration)+"秒钟左右才能再次使用『不自持』\n");
	
	amount = skill *2;		
	message_vision(BBLU + HIM "\n$N尖啸一声，左手虚晃，幻化出六朵奇花，每朵花又有纯白光芒与之相接，如白色光轮状。\n"NOR, me);		
	
	me->set("timer/pfm/khl_buzichi", time());
	if (target->query("boss")|| target->query("big_boss"))
		duration = 10;
	else
		duration = 20;
		
	me->add_temp("apply/herb",amount);
	if (COMBAT_D->do_magic_attack(me, target, "herb", "kee", 0)) {	
	    message_vision(WHT"$N目光为白轮所炫，意动神摇。\n"NOR, target);
	    buff = 
			([
				"caster": me,
				"who":   target,
				"type":  "lowresist-kee",
				"att":	 "curse",
				"name":	"云梦五花锦·不自持",
				"buff1":"apply/intelligence",
				"buff1_c": -10,
				"buff2": "apply/composure",
				"buff2_c": -10,	
				"buff3": "resistance/kee",
				"buff3_c": -10,  
				"time":    duration,
				"buff_msg": "",
				"disa_msg":WHT"$N"NOR WHT"慢慢地终于缓过气来。\n"NOR,
				"disa_type": 1,
			]);
		ANNIE_D->buffup(buff);	
    }	else
        	message_vision(YEL"$N屏息凝气，不为所动。\n"NOR, target);	
	
	me->add_temp("apply/herb",-amount);
		
	return 1;

}
